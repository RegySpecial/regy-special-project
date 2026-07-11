#include"../../include/main/c++/mainWindow.hpp"
mainWindow::mainWindow(int argc,char*argv[],char*envp[],const char*title){
  this->display=XOpenDisplay(NULL);
  XVisualInfo visualInfo;
  XSetWindowAttributes mainWindowAttributes={
    .background_pixel=this->border.width,
    .border_pixel=this->background.color,
    .event_mask=ExposureMask|ResizeRedirectMask|StructureNotifyMask
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
    visualInfo.depth,
    visualInfo.c_class,
    visualInfo.visual,
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
void mainWindow::onresize(mainWindow*target,XEvent*event){
  for(unsigned long i=0;i<target->subWindows.size;i++)
    XResizeWindow(target->display,target->subWindows[i],event->xresizerequest.width,event->xresizerequest.height);
}
void mainWindow::onclientmessage(mainWindow*target,XEvent*event){
  //work in progress
  if((Atom)event->xclient.data.l == XInternAtom(this->display, "WM_DELETE_WINDOW", 0))
    XSendEvent(this->display,mainScreenButtons[0][1],0,ButtonPressMask,event);
}