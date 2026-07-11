#include "../../../include/lib/c++/x11/display.hpp"
x11::display::display(char*displayName){
  this->displayName=displayName;
  this->nativeHandle=XOpenDisplay(this->displayName);
  if(this->nativeHandle)
    OKMessage("The connection to the X Graphic Server has been established successfully!");
  else{
    failureMessage("Failed to connect to X Graphic server!");
    return;
  }
  this->connectionNumber=XConnectionNumber(this->nativeHandle);
  this->screenNumber=XDefaultScreen(this->nativeHandle);
  this->screen=XScreenOfDisplay(this->nativeHandle,this->screenNumber);
  this->rootWindow=XRootWindow(this->nativeHandle,this->screenNumber);
  this->vendorRelease=XVendorRelease(this->nativeHandle);
}
void x11::display::unlock(){
  XUnlockDisplay(this->nativeHandle);
}
void x11::display::lock(){
  XLockDisplay(this->nativeHandle);
}
x11::display::~display(){
  assert(XCloseDisplay(this->nativeHandle));
}
int x11::display::nextEvent(XEvent*event){
  return XNextEvent(this->nativeHandle,event);
}
void x11::display::flush(){
  XFlush(this->nativeHandle);
}
int x11::display::storeBuffer(const char*bytes,int nbytes,int buffer){
  return XStoreBuffer(this->nativeHandle,bytes,nbytes,buffer);
}
int x11::display::storeBytes(const char*bytes,int nbytes){
  return XStoreBytes(this->nativeHandle,bytes,nbytes);
}
int x11::display::sync(bool discard){
  return XSync(this->nativeHandle,discard);
}