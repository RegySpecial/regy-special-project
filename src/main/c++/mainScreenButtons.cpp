#include "../../include/main/c++/mainScreenButtons.hpp"

mainScreenButton::mainScreenButton(mainWindow*root,const char*text){
  XSetWindowAttributes mainScreenButtonsAttributes={
    .background_pixel=this->background.color,//set window background color to blue on RGB format 00000000|00000000|11111111
    .border_pixel=this->border.color,//set window border color to red on RGB format 11111111|00000000|00000000
    .event_mask=this->eventMask,
    .do_not_propagate_mask=this->dontPropagateMask
  };
  this->root=root;
  this->title=text;
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    1,
    this->root->visualInfo.depth,
    this->root->visualInfo.c_class,
    this->root->visualInfo.visual,
    this->attributeMask,
    &mainScreenButtonsAttributes
  );
  XMapRaised(this->root->display,this->id);
}
void mainWindow::onclientmessage(XEvent*event,void*extraArgs){
  //work in progress
  mainScreenButton*exitButton=(mainScreenButton*)extraArgs;
  if((Atom)event->xclient.data.l == XInternAtom(this->display, "WM_DELETE_WINDOW", 0))
    XSendEvent(this->display,exitButton->id,0,ButtonPressMask,event);
}
void mainScreenButton::onclick(XEvent*event,void*extraArgs){
  gameContextStructure*data=(gameContextStructure*)extraArgs;
  if (!compare<const char>(this->title,"exit",4)) {
    dialog exitDialog(this->root,dialogType_exit);
  }
}