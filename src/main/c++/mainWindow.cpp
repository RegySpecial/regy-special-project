/*
*@description C++ source code for the main window of the videogame
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 July 6th Monday 15:50:56
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/mainWindow.hpp"
#if defined __WIN32 || defined __WIN64
mainWindow::mainWindow(HINSTANCE hInst, HINSTANCE hInstPrev, char* cmdline, int cmdshow, const char *title)
{
  this->hInst = hInst;
  this->hPrevInst = hPrevInst;
  this->cmdLine = cmdLine;
  this->cmdShow = cmdShow;

  this->x = 0;
  this->y = 0;
  this->width = GetSystemMetrics(SM_CXSCREEN);
  this->height = GetSystemMetrics(SM_CYSCREEN);
  this->title = title;
  this->background.color = 0;

  WNDCLASSA windowClass = {
    .style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
    .lpfnWndProc = WindowProc,
    .hInstance = this->hInst,
    .hIcon = (HICON) LoadImageA
    (
      windowClass.hInstance,
      "F:/Regy Special/Regy Special Project/blob/images/RegySpecial.ico",
      IMAGE_ICON,
      0,
      0,
      LR_LOADFROMFILE
    ),
    .hCursor = LoadCursor(windowClass.hInstance,IDC_ARROW),
    .hbrBackground = 0,
    .lpszMenuName = this->title,
    .lpszClassName = this->title
  };

  assert(RegisterClassA(&windowClass));

  this->id = CreateWindowA
  (
    windowClass.lpszClassName,//window class name
    this->title,//window title
    WS_POPUP | WS_VISIBLE,//window style
    this->x,//window x
    this->y,//window y
    this->width,//window width
    this->height,//window height
    NULL,//window parent
    (HMENU)MainWindow_MainWindow,//window menu
    windowClass.hInstance,//window instance
    NULL//window extra info(lparam)
  );

  HANDLE_WM_PAINT(MainWindow,0,0,PaintTheIntro);
}
#else
mainWindow::mainWindow(int argc, char *argv[], char *envp[],const char *title)
{
  this->argc = argc;
  this->argv = argv;
  this->envp = envp;

  this->display = 
    #ifdef WaylandEnabled
    wl_display_connnect
    #else
    XOpenDisplay
    #endif
    (0);

  if (!this->display)
  {
    failureMessage
    (
      "Cannot establish a connection with the "
      #ifdef WaylandEnabled
      "Wayland"
      #else
      "X"
      #endif
      " Graphic Server"
    );
    abort();
  }

  this->title = title;

  this->screen = XDefaultScreenOfDisplay(this->display);

  this->x = 0;
  this->y = 0;
  this->width = this->screen->width;
  this->height = this->screen->height;

  this->background.color = 0;
  this->border.color = 0xffffff;
  this->eventMask = ExposureMask | ResizeRedirectMask;
  this->attributeMask = CWBorderWidth | CWBackPixel | CWBorderPixel | CWEventMask;

  XSetWindowAttributes mainWindowAttributes = {
    .background_pixel = this->background.color,
    .border_pixel = this->border.color,
    .event_mask = this->eventMask
  };

  XSizeHints
    mainWindowBounds = {
      .x = this->x,
      .y = this->y,
      .max_width = this->width,
      .max_height = this->height
    };
  
  this->id=XCreateWindow(
    this->display,
    this->screen->root,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->screen->root_depth,
    InputOutput,
    this->screen->root_visual,
    this->attributeMask,
    &mainWindowAttributes
  );

  XSetStandardProperties(
    this->display,
    this->id,
    this->title,
    NULL,
    0,
    this->argv,
    this->argc,
    &mainWindowBounds
  );

  XMapRaised(this->display, this->id);

  this->onResize = [](XResizeRequestEvent *event, void *extraArgs){
    mainWindow *self = (mainWindow*) extraArgs;
    for(unsigned long i=0;i<self->subWindows.size;i++)
      XResizeWindow(self->display,self->subWindows[i],event->width,event->height);
  };
}
#endif
mainWindow::~mainWindow()
{
#if defined __WIN32 || defined __WIN64
  assert(UnregisterClassA(&windowClass));
  assert(DestroyWindow(this->id));
#elifdef WaylandEnabled
  wl_display_disconnect(this->display);
#else
  XDestroySubwindows(this->display,this->id);
  XDestroyWindow(this->display,this->id);
  XCloseDisplay(this->display);
#endif
}

int mainWindow::show(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->display, this->id);
#endif
}

int mainWindow::hide(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->display, this->id);
#endif
}