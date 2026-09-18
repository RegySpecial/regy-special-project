#include "../../include/main/c++/mainScreenButtons.hpp"

mainScreenButton::mainScreenButton(mainWindow*root,const char*text){
  this->root = root;
  this->text = {
    text,
    20,
    20,
    0,
    0,
    255 << 16,
    {
      "-urw-century schoolbook l-regular-r-normal--0-0-0-0-p-0-iso8859-15",
      15,
      1
    }
  };

  this->background.color = 255;
  this->border = {
    1,
    this->text.color
  };

  this->eventMask = ExposureMask | ButtonPressMask | EnterWindowMask | LeaveWindowMask;
  this->dontPropagateMask = ButtonPressMask;
  this->graphicMask = GCForeground | GCBackground | GCFont;
  XSetWindowAttributes mainScreenButtonsAttributes={
    .background_pixel = this->background.color,//set window background color to blue on RGB format 00000000|00000000|11111111
    .border_pixel = this->border.color,//set window border color to red on RGB format 11111111|00000000|00000000
    .event_mask = this->eventMask,
    .do_not_propagate_mask = this->dontPropagateMask
  };
  
  this->id=XCreateWindow(
    this->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    this->root->screen->root_depth,
    InputOutput,
    this->root->screen->root_visual,
    this->attributeMask,
    &mainScreenButtonsAttributes
  );

  XMapRaised(this->root->display,this->id);

  XGCValues gcValues = {
    .foreground = this->text.color,
    .background = this->background.color,
    .font = XLoadFont(this->root->display, this->text.font.family)
  };

  this->graphicId = XCreateGC(this->root->display, this->id, this->graphicMask, &gcValues);

  this->onButtonDown = [](XButtonPressedEvent *event, void *extraArgs){
    beep(1000,100);
    dialog*targetDialog=(dialog*)extraArgs;
    targetDialog->show(0);
  };

  this->onPointerIn = [](XEnterWindowEvent *event, void *extraArgs){
    mainScreenButton *self = (mainScreenButton*) extraArgs;
    self->background.color = ~self->background.color;
    self->text.color = ~self->text.color;
    self->border.color = ~self->border.color;
    XSetWindowBackground(self->root->display, self->id, self->background.color);
    XSetWindowBorder(self->root->display, self->id, self->border.color);
    XClearWindow(self->root->display, self->id);
    XSetForeground(
      self->root->display,
      self->graphicId,
      self->text.color
    );
  };

  this->onPointerOut = [](XLeaveWindowEvent *event, void *extraArgs){
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

  this->root->onClientMessage = [](XClientMessageEvent *event, void *extraArgs){
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

  this->onExpose = [](XExposeEvent *event, void *extraArgs){
    mainScreenButton *self = (mainScreenButton*) extraArgs;
    XDrawString(
      self->root->display,
      self->id,
      self->graphicId,
      self->text.x,
      self->text.y,
      self->text.value,
      strlen(self->text.value)
    );
  };

  this->root->subWindows.push(this->id);
}
mainScreenButton::~mainScreenButton(){
  this->root->subWindows.remove(this->id);
  XFreeGC(this->root->display,this->graphicId);
}

int mainScreenButton::show(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->display, this->id);
#endif
}

int mainScreenButton::hide(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->display, this->id);
#endif
}