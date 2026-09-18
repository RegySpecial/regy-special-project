/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 20th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/gameModeButtons.hpp"
gameModeButton::gameModeButton(dialog *root, const char *title, unsigned long color)
{
  this->root = root;
  this->title = title;
  this->text.color = color;

  this->background.color = 0;
  this->border.color = this->text.color;
  this->eventMask = ButtonPressMask | ExposureMask;
  this->dontPropagateMask = ButtonPress;
  this->graphicMask = GCForeground;

  XSetWindowAttributes gameModeButtonAttributes{
    .background_pixel = this->background.color,
    .border_pixel = this->border.color,
    .event_mask = this->eventMask,
    .do_not_propagate_mask = this->dontPropagateMask
  };
  this->id = XCreateWindow
  (
    this->root->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->root->root->screen->root_depth,
    InputOutput,
    this->root->root->screen->root_visual,
    this->attributeMask,
    &gameModeButtonAttributes
  );
  XGCValues gcValues = {
    .foreground = this->text.color
  };
  this->graphicId = XCreateGC(this->root->root->display, this->id, this->graphicMask, &gcValues);
  this->root->subWindows.push(this->id);
}
gameModeButton::~gameModeButton(){
  this->root->subWindows.remove(this->id);
  XFreeGC(this->root->root->display, this->graphicId);
}

int gameModeButton::show(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->root->display, this->id);
#endif
}

int gameModeButton::hide(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->root->display, this->id);
#endif
}