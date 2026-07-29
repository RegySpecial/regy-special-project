#include "../../include/main/c++/form.hpp"

form::form(mainWindow*root){
  this->root=root;
  this->x=this->root->width*20/100,//20% of screen.width
  this->y=this->root->height*20/100,//20% of screen.width
  this->width=this->root->width-2*this->root->width*20/100,//screen.width-2*form.x
  this->height=this->root->height-2*this->root->height*20/100,//screen.width-2*form.x
  this->border={
    2,//width
    0//color
  };
  XSetWindowAttributes formAttributes{
    .background_pixel=(this->background.color=0xffffff),
    .border_pixel=this->border.color,
    .event_mask=(this->eventMask=ExposureMask)
  };
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,//20% of screen.width
    this->y,//20% of screen.width
    this->width,//screen.width-2*form.x
    this->height,//screen.width-2*form.x
    this->border.width,
    this->root->visualInfo.depth,//depth
    this->root->visualInfo.c_class,//window class
    this->root->visualInfo.visual,//visual
    (this->attributeMask=CWBorderPixel|CWBackPixel|CWEventMask),
    &formAttributes
  );
}
form::~form(){
  XDestroySubwindows(this->root->display,this->id);
}