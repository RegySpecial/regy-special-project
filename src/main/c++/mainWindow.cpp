#include"../../include/main/c++/mainWindow.hpp"
mainWindow::mainWindow(const char*title){
  this->display=XOpenDisplay(NULL);
  XVisualInfo visualInfo;
  XSetWindowAttributes mainWindowAttributes={
    .background_pixel=this->border.width,
    .border_pixel=this->background.color,
    .event_mask=ExposureMask|ResizeRedirectMask|StructureNotifyMask
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
}
mainWindow::~mainWindow(){
  XDestroySubwindows(this->display,this->id);
  XDestroyWindow(this->display,this->id);
  XCloseDisplay(this->display);
}
void mainWindow::onresize(mainWindow*target,XEvent*event){
  
}
void mainWindow::onclientmessage(mainWindow*target,XEvent*event){
  if((Atom)event->xclient.data.l == XInternAtom(this->display, "WM_DELETE_WINDOW", 0))
    XSendEvent(this->display,mainScreenButtons[0][1],0,ButtonPressMask,event);
}