#include "../../../include/lib/c++/x11/pixmap.hpp"
x11::pixmap::pixmap(x11::drawable*drawable){
  this->drawable=drawable;
  this->id=XCreatePixmap(
    this->drawable->display->nativeHandle,
    this->drawable->id,
    this->width,
    this->height,
    this->drawable->display->depth
  );
}
x11::pixmap::~pixmap(){
  XFreePixmap(
    this->drawable->display->nativeHandle,
    this->drawable->id
  );
}