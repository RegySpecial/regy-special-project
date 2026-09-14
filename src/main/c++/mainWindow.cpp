/*
*@description C++ source code for the main window of the videogame
*@author Regy Special
*@date (First version [Linux/Parrot OS]) 2026 July 6th Monday 15:50:56
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/mainWindow.hpp"
#if defined __WIN32 || defined __WIN64
mainWindow::mainWindow(HINSTANCE hInst, HINSTANCE hInstPrev, char* cmdline, int cmdshow)
{
  WNDCLASSA windowClass = {
    .style=CS_HREDRAW|CS_VREDRAW|CS_OWNDC,
    .lpfnWndProc = WindowProc,
    .hInstance=hInst,
    .hIcon=(HICON)LoadImageA(
      windowClass.hInstance,
      "F:/Regy Special/Regy Special Project/blob/images/RegySpecial.ico",
      IMAGE_ICON,
      0,
      0,
      LR_LOADFROMFILE
    ),
    .hCursor=LoadCursor(windowClass.hInstance,IDC_ARROW),
    .hbrBackground=CreateSolidBrush(0),
    .lpszMenuName="RegySpecial",
    .lpszClassName="RegySpecial"
  };
  assert(RegisterClassA(&windowClass));
}
#else
mainWindow::mainWindow(int argc,char*argv[],char*envp[],const char*title){
  this->argc=argc;
  this->argv=argv;
  this->envp=envp;
  this->display=XOpenDisplay(NULL);
  Screen*screen=XScreenOfDisplay(this->display,this->visualInfo.screen);
  XSetWindowAttributes mainWindowAttributes={
    .background_pixel=(this->background.color=0),
    .border_pixel=(this->background.color=0xffffff),
    .event_mask=(this->eventMask=ExposureMask|ResizeRedirectMask)
  };
  XSizeHints
    mainWindowBounds={
      .x=(this->x=0),
      .y=(this->y=0),
      .max_width=(this->width=screen->width),
      .max_height=(this->height=screen->height)
    };
  this->id=XCreateWindow(
    this->display,
    XRootWindow(this->display,this->visualInfo.screen),
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->visualInfo.depth,
    this->visualInfo.c_class,
    this->visualInfo.visual,
    (this->attributeMask=CWBorderWidth|CWBackPixel|CWBorderPixel|CWEventMask),
    &mainWindowAttributes
  );
  XSetStandardProperties(
    this->display,
    this->id,
    (this->title=title),
    NULL,
    0,
    this->argv,
    this->argc,
    &mainWindowBounds
  );
  XMapRaised(this->display, this->id);
  this->onResize = [](XResizeRequestEvent*event,void*extraArgs){
    mainWindow *self = (mainWindow*) extraArgs;
    for(unsigned long i=0;i<self->subWindows.size;i++)
      XResizeWindow(self->display,self->subWindows[i],event->width,event->height);
  };
}
#endif
mainWindow::~mainWindow(){
#if defined __WIN32 || defined __WIN64
  assert(DestroyWindow(this->id));
#elifdef WaylandEnabled

#else
  XFreeGC(this->display,this->graphicId);
  XDestroySubwindows(this->display,this->id);
  XDestroyWindow(this->display,this->id);
  XCloseDisplay(this->display);
#endif
}
int mainWindow::show(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->display,this->id);
#endif
}
int mainWindow::hide(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->display,this->id);
#endif
}