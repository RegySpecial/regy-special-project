#include "../../include/main/c++/mainWindow.hpp"

mainWindow::mainWindow(int argc,char*argv[],char*envp[],const char*title){
  this->display=XOpenDisplay(NULL);
  XSetWindowAttributes mainWindowAttributes={
    .background_pixel=this->border.width,
    .border_pixel=this->background.color,
    .event_mask=this->eventMask
  };
  XSizeHints
    mainWindowBounds={
      .x=0,
      .y=0,
      .max_width=this->width,
      .max_height=this->height
    };
  this->id=XCreateWindow(
    this->display,
    XRootWindow(this->display,visualInfo.screen),
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->visualInfo.depth,
    this->visualInfo.c_class,
    this->visualInfo.visual,
    this->attributeMask,
    &mainWindowAttributes
  );
  XSetStandardProperties(
    this->display,
    this->id,
    "Grisly mountains",
    NULL,
    0,
    argv,
    argc,
    &mainWindowBounds
  );
}
mainWindow::~mainWindow(){
  XDestroySubwindows(this->display,this->id);
  XDestroyWindow(this->display,this->id);
  XCloseDisplay(this->display);
}
void mainWindow::onresize(XEvent*event,void*target){
  for(unsigned long i=0;i<this->subWindows.size;i++)
    XResizeWindow(this->display,this->subWindows[i],event->xresizerequest.width,event->xresizerequest.height);
}