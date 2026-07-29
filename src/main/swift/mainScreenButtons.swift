#include "../../include/main/c++/mainScreenButtons.hpp"

mainScreenButton::mainScreenButton(mainWindow*root,const char*text){
  XSetWindowAttributes mainScreenButtonsAttributes={
    .background_pixel=(this->background.color=255),//set window background color to blue on RGB format 00000000|00000000|11111111
    .border_pixel=(this->border.color255<<16),//set window border color to red on RGB format 11111111|00000000|00000000
    .event_mask=(this->eventMask=ExposureMask|ButtonPressMask|EnterWindowMask|LeaveWindowMask),
    .do_not_propagate_mask=(this->dontPropagateMask=ButtonPressMask)
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
  XGCValues gcValues={
    .foreground=(this->text.color=255<<16),
    .background=(this->background.color=255),
    .font=XLoadFont(this->root->display,(this->text.font.family="-urw-century schoolbook l-regular-r-normal--0-0-0-0-p-0-iso8859-15"))
  };
  this->graphicId=XCreateGC(this->root->display,this->id,(this->graphicMask=GCForeground|GCBackground|GCFont),&gcValues);
}
int mainScreenButton::show(unsigned int microseconds){
  usleep(microseconds);
  return XMapRaised(this->root->display,this->id);
}
int mainScreenButton::hide(unsigned int microseconds){
  usleep(microseconds);
  return XUnmapWindow(this->root->display,this->id);
}
void mainScreenButton::onButtonDown(XButtonPressedEvent*event,void*extraArgs){
  beep(1000,100);
  dialog*targetDialog=(dialog*)extraArgs;
  targetDialog->show(0);
}
void mainScreenButton::onPointerIn(XEnterWindowEvent*event,void*extraArgs){
  this->background.color~=this->background.color;
  this->text.color~=this->text.color;
  this->border.color~=this->border.color;
  XSetWindowBackground(this->root->display,this->id,this->background.color);
  XSetWindowBorder(this->root->display,this->id,this->border.color);
  XClearWindow(this->root->display,this->id);
  XSetForeground(
    this->root->display,
    this->id,
    this->graphicId,
    this->text.color
  );
}
void mainScreenButton::onPointerOut(XLeaveWindowEvent*event,void*extraArgs){
  XEvent event;
  XSendEvent(
    this->root->display,
    this->id,
    0,
    EnterNotifyMask,
    &event
  );
}
void mainWindow::onClientMessage(XClientMessageEvent*event,void*extraArgs){
  mainScreenButton*exitButton=(mainScreenButton*)extraArgs;
  XEvent eventOutput;
  if((Atom)event->data.l == XInternAtom(this->display, "WM_DELETE_WINDOW", 0))
    XSendEvent(
      this->display,
      exitButton->id,
      0,
      ButtonPressMask,
      &eventOutput
    );
}
void mainScreenButton::onExpose(XExposeEvent*event,void*extraArgs){
  XDrawString(
    this->root->display,
    this->id,
    this->graphicId,
    (this->text.x=20),
    (this->text.y=20),
    this->text.value,
    strlen(this->text.value)
  );
}
mainScreenButton::~mainScreenButton(){
  XFreeGC(this->root->display,this->graphicId);
}
