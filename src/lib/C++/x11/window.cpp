#include"../../../include/lib/c++/x11/window.hpp"
x11::window::window(x11::display*display){
  this->display=display;
  XSetWindowAttributes windowAttributes={
    .background_pixel=this->background.color,
    .win_gravity=this->gravity,
    .event_mask=this->eventMask,
    .do_not_propagate_mask=this->doNotPropagateMask,
  };
  this->id=XCreateWindow(
    this->display->nativeHandle,
    this->display->rootWindow,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->display->visualInfo.depth,
    this->display->visualInfo.c_class,
    this->display->visualInfo.visual,
    this->propertyMask,
    &windowAttributes
  );
}
int x11::window::selectInput(long eventMask){
  this->eventMask=eventMask;
  return XSelectInput(this->display->nativeHandle,this->id,this->eventMask);
}
int x11::window::checkEvent(long eventMask){
  XEvent event;
  return XCheckWindowEvent(this->display->nativeHandle,this->id,eventMask,&event);
}
int x11::window::sendEvent(bool propagation,long eventMask,XEvent*eventSend){
  return XSendEvent(
    this->display->nativeHandle,
    this->id,
    propagation,
    eventMask,
    eventSend
  );
}
x11::window::~window(){
  XDestroySubwindows(this->display->nativeHandle,this->id);
  XDestroyWindow(this->display->nativeHandle,this->id);
}