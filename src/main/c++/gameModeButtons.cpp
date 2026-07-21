/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 20th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/gameModeButtons.hpp"
gameModeButton::gameModeButton(dialog*root,const char*title){
  XSetWindowAttributes gameModeButtonAttributes{
    .background_pixel=0,
    .border_pixel=0x808080,
    .event_mask=(this->eventMask = ButtonPressMask|ExposureMask),
    .do_not_propagate_mask=(this->dontPropagateMask = ButtonPress)
  };
  this->root=root;
  this->title=title;
  this->id=XCreateWindow(
    this->root->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->root->root->visualInfo.depth,
    this->root->root->visualInfo.c_class,
    this->root->root->visualInfo.visual,
    this->attributeMask,
    &gameModeButtonAttributes
  );
}