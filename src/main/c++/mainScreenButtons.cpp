#include "../../include/main/c++/mainScreenButtons.hpp"

mainScreenButton::mainScreenButton(mainWindow*root,const char*text){
  this->root = root;
  this->text.value = text;

  Screen*screen = XDefaultScreenOfDisplay(this->root->display);

  XSetWindowAttributes mainScreenButtonsAttributes={
    .background_pixel=(this->background.color=255),//set window background color to blue on RGB format 00000000|00000000|11111111
    .border_pixel=(this->border.color=255<<16),//set window border color to red on RGB format 11111111|00000000|00000000
    .event_mask=(this->eventMask=ExposureMask|ButtonPressMask|EnterWindowMask|LeaveWindowMask),
    .do_not_propagate_mask=(this->dontPropagateMask=ButtonPressMask)
  };
  
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    1,
    screen->root_depth,
    InputOutput,
    screen->root_visual,
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

  this->onButtonDown = [](XButtonPressedEvent*event,void*extraArgs){
    beep(1000,100);
    dialog*targetDialog=(dialog*)extraArgs;
    targetDialog->show(0);
  };

  this->onPointerIn = [](XEnterWindowEvent*event,void*extraArgs){
    mainScreenButton *self = (mainScreenButton*) extraArgs;
    self->background.color=~self->background.color;
    self->text.color=~self->text.color;
    self->border.color=~self->border.color;
    XSetWindowBackground(self->root->display,self->id,self->background.color);
    XSetWindowBorder(self->root->display,self->id,self->border.color);
    XClearWindow(self->root->display,self->id);
    XSetForeground(
      self->root->display,
      self->graphicId,
      self->text.color
    );
  };

  this->onPointerOut = [](XLeaveWindowEvent*event,void*extraArgs){
    mainScreenButton *self = (mainScreenButton*)extraArgs;
    XEvent eventOutput;
    XSendEvent(
      self->root->display,
      self->id,
      0,
      EnterWindowMask,
      &eventOutput
    );
  };

  root->onClientMessage = [](XClientMessageEvent*event,void*extraArgs){
    mainScreenButton*exitButton = (mainScreenButton*)extraArgs;
    XEvent eventOutput;
    if((Atom)event->data.l == XInternAtom(exitButton->root->display, "WM_DELETE_WINDOW", 0))
      XSendEvent(
        exitButton->root->display,
        exitButton->id,
        0,
        ButtonPressMask,
        &eventOutput
      );
  };

  this->onExpose = [](XExposeEvent*event,void*extraArgs){
    mainScreenButton *self = (mainScreenButton*) extraArgs;
    XDrawString(
      self->root->display,
      self->id,
      self->graphicId,
      (self->text.x=20),
      (self->text.y=20),
      self->text.value,
      strlen(self->text.value)
    );
  };
}
mainScreenButton::~mainScreenButton(){
  XFreeGC(this->root->display,this->graphicId);
}
int mainScreenButton::show(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->display,this->id);
#endif
}
int mainScreenButton::hide(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->display,this->id);
#endif
}