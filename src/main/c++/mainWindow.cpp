/*
*@description C++ source code for the main window of the videogame
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 July 6th Monday 15:50:56
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/mainWindow.hpp"
window::window(application *app, const char *title)
{
  #if defined __WIN32 || defined __WIN64
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
#else
  this->app = app;

  this->title = title;

  this->x = 0;
  this->y = 0;
  this->width = 
  #if defined __WIN32 || defined __WIN64
  GetSystemMetrics(SM_CXSCREEN)
  #else
  this->app->screen->width
  #endif
  ;
  this->height = 
  #if defined __WIN32 || defined __WIN64
  GetSystemMetrics(SM_CYSCREEN)
  #else
  app->screen->height
  #endif
  ;

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
  
  this->id = XCreateWindow
  (
    app->display,
    app->screen->root,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->app->screen->root_depth,
    InputOutput,
    this->app->screen->root_visual,
    this->attributeMask,
    &mainWindowAttributes
  );

  XSetStandardProperties
  (
    app->display,
    this->id,
    this->title,
    NULL,
    0,
    this->app->argv,
    this->app->argc,
    &mainWindowBounds
  );

  XMapRaised(this->app->display, this->id);

  this->onResize = [](XResizeRequestEvent *event, void *extraArgs)
{
    window *self = (window *) extraArgs;
    for(unsigned long i = 0; i < self->subwidget.size;i++)
      XResizeWindow(self->app->display, self->id, event->width,event->height);
  };
#endif
}

window::~window()
{
#if defined __WIN32 || defined __WIN64
  assert(UnregisterClassA(&windowClass));
  assert(DestroyWindow(this->id));
#else
  XDestroySubwindows(this->app->display, this->id);
  XDestroyWindow(this->app->display, this->id);
#endif
}

int window::show(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->app->display, this->id);
#endif
}

int window::hide(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->app->display, this->id);
#endif
}

bool window::addEventListener(unsigned char eventState, void (*listener)(event *event, window *target, void *extraArguments))
{
  if (0 > eventState && eventState > eventState_lastEvent)
  {
    errorMessage("Invalid event identifier\n");
    return 0;
  }
  event eventClass;
  eventClass.target = this;
  this->eventMask = setBit<long>(this->eventMask, eventState);
  XSelectInput(this->app->display, this->id, this->eventMask);
  this->app->eventQueue.push(eventClass);
  return 1;
}

bool window::removeEventListener(unsigned char eventState)
{
  if (0 > eventState && eventState > eventState_lastEvent)
  {
    errorMessage("Invalid event identifier\n");
    return 0;
  }
  this->eventMask = clearBit<long>(this->eventMask, eventState);
  XSelectInput(this->app->display, this->id, this->eventMask);
  this->app->eventQueue.pop();
  return 1;
}