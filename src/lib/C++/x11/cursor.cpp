#include "../../../include/lib/c++/x11/cursor.hpp"
x11::cursor::cursor(x11::display*display,unsigned int shape){
  this->display=display;
  this->shape=shape;
  this->id=XCreateFontCursor(this->display->nativeHandle,shape);
}
x11::cursor::cursor(x11::display*display,Font sourceFont,Font maskFont,char sourceChar,char maskChar,XColor*foreground,XColor*background){
  this->display=display;
  this->shape=shape;
  this->id=XCreateGlyphCursor(
    this->display->nativeHandle,
    sourceFont,
    maskFont,
    sourceChar,
    maskChar,
    foreground,
    background
  );
}
x11::cursor::~cursor(){
  XFreeCursor(this->display->nativeHandle,this->id);
}