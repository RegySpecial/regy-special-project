/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 19th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/mainDialogs.hpp"

dialog::dialog(mainWindow*root,unsigned char type){
  this->root=root;
  this->type=type;
  XSetWindowAttributes dialogAttributes={
    .background_pixel=this->border.width,
    .border_pixel=this->background.color,
    .event_mask=this->eventMask
  };
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->root->visualInfo.depth,
    this->root->visualInfo.c_class,
    this->root->visualInfo.visual,
    this->attributeMask,
    &dialogAttributes
  );
  XMapRaised(this->root->display,this->id);
}
dialog::~dialog(){
  XDestroySubwindows(this->root->display,this->id);
}