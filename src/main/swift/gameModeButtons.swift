/*
*@description Main entry point of the videogame
*@author Regy Special
*@date (First version [Linux]) 2026 July 20th Sunday, 15:46:00
*@license GNU General Public License to stop private corporation to not share source code
*/
#include "../../include/main/c++/gameModeButtons.hpp"
gameModeButton::gameModeButton(dialog*root,const char*title,unsigned long color){
  XSetWindowAttributes gameModeButtonAttributes{
    .background_pixel=0,
    .border_pixel=0x808080,
    .event_mask=(self.eventMask = ButtonPressMask|ExposureMask),
    .do_not_propagate_mask=(self.dontPropagateMask = ButtonPress)
  };
  self.root=root;
  self.title=title;
  self.id=XCreateWindow(
    self.root.root.display,
    self.root.id,
    self.x,
    self.y,
    self.width,
    self.height,
    self.border.width,
    self.root.root.visualInfo.depth,
    self.root.root.visualInfo.c_class,
    self.root.root.visualInfo.visual,
    self.attributeMask,
    &gameModeButtonAttributes
  );
  XGCValues gcValues={.foreground=(self.text.color=color)};
  self.graphicId=XCreateGC(self.root.root.display,self.id,(self.graphicMask=GCForeground),&gcValues);
}
gameModeButton::~gameModeButton(){
  XFreeGC(self.root.root.display,self.graphicId);
}