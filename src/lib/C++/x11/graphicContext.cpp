#include"../../../include/lib/c++/x11/graphicContext.hpp"
x11::graphicContext::graphicContext(x11::drawable*drawable){
  this->drawable=drawable;
  XGCValues gcValues;
  this->drawable->display->nativeHandle;
  this->id=XCreateGC(this->drawable->display->nativeHandle,this->drawable->id,this->propertyMask,&gcValues);
}
inline void x11::graphicContext::flush(){
  XFlushGC(this->drawable->display->nativeHandle,this->id);
}
int x11::graphicContext::drawString(int x,int y,char*string,int length){
  this->string={x,y,string,length};
  return XDrawString(
    this->drawable->display->nativeHandle,
    this->drawable->id,
    this->id,
    this->string.x,
    this->string.y,
    this->string.string,
    this->string.length
  );
}
x11::graphicContext::~graphicContext(){
  XFreeGC(this->drawable->display->nativeHandle,this->id);
}