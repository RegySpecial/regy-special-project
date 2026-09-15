#include "../../include/main/c++/form.hpp"

form::form(mainWindow*root){
  this->root = root;

  Screen *screen = XDefaultScreenOfDisplay(this->root->display);

  this->x = this->root->width * 20 / 100,//20% of screen.width
  this->y = this->root->height * 20 / 100,//20% of screen.width
  this->width = this->root->width - 2 * this->root->width * 20 / 100,//screen.width-2*form.x
  this->height = this->root->height - 2 * this->root->height * 20 / 100,//screen.width-2*form.x
  this->border = {
    2,//width
    0//color
  };
  this->background.color = 0xffffff;
  this->eventMask = ExposureMask;
  this->attributeMask = CWBorderPixel | CWBackPixel | CWEventMask;

  XSetWindowAttributes formAttributes{
    .background_pixel = this->background.color,
    .border_pixel = this->border.color,
    .event_mask = this->eventMask
  };
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,//20% of screen.width
    this->y,//20% of screen.width
    this->width,//screen.width-2*form.x
    this->height,//screen.width-2*form.x
    this->border.width,
    screen->root_depth,//depth
    InputOutput,//window class
    screen->root_visual,//visual
    this->attributeMask,
    &formAttributes
  );

  this->root->subWindows.push(this->id);
}
form::~form(){
  this->root->subWindows.remove(this->id);
  XDestroySubwindows(this->root->display, this->id);
}
int form::show(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->display,this->id);
#endif
}
int form::hide(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->display,this->id);
#endif
}