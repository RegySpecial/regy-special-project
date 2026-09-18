#include "../../include/main/c++/formTextBox.hpp"

formTextBox::formTextBox(form *root)
{

  this->root = root;

  Screen *screen = XDefaultScreenOfDisplay(this->root->root->display);

  this->x = this->root->width * 5 / 100;
  this->y = this->root->height * 5 / 100;
  this->width = this->root->width - 2 * (this->root->width*10/100);
  this->height = this->root->height * 20 / 100;
  this->border.width = 1;
  this->background.color = 0;
  this->border.color = 255 << 8;
  this->text.x = 20;
  this->text.y = 20;
  this->eventMask = KeyPressMask | FocusChangeMask | EnterWindowMask | LeaveWindowMask;
  this->dontPropagateMask = KeyPressMask;
  this->attributeMask = CWBackPixel | CWBorderWidth | CWBorderPixel | CWEventMask | CWDontPropagate;
  this->graphicMask = GCForeground;

  XSetWindowAttributes formTextBoxAttributes={
    .background_pixel = this->background.color,
    .border_pixel = this->border.color,
    .event_mask = this->eventMask,
    .do_not_propagate_mask = this->dontPropagateMask
  };

  this->id=XCreateWindow(
    this->root->root->display,
    this->root->id,
    this->x,
    this->y,
    this->width,
    this->height,
    this->border.width,
    screen->root_depth,
    InputOutput,
    screen->root_visual,
    this->attributeMask,
    &formTextBoxAttributes
  );
  XGCValues gcValues={
    .foreground=(this->text.color=255<<8)
  };
  this->graphicId=XCreateGC(
    this->root->root->display,
    this->id,
    this->graphicMask,
    &gcValues
  );

  this->onKeyDown = [](XKeyPressedEvent *event, void *extraArgs){
    struct messageStructure
    {
      gameContextStructure *gameCtxtStruct;
      formTextBox *self;
    };

    struct messageStructure* msgStruct = (messageStructure*) extraArgs;
    char trueKey = (char)XkbKeycodeToKeysym
    (
      msgStruct->self->root->root->display,//X display
      event->keycode,//key event key code
      0,//key group
      readBit<unsigned char>(event->state, ShiftMapIndex) ^
      readBit<unsigned char>(event->state, LockMapIndex)//key level
    );
    //Mod2=Alt
    switch (event->keycode)
    {
      case 22://Backspace key case
        if (!msgStruct->self->pointer)
          beep(1000,100);
        else
        {
          msgStruct->self->pointer-=1;
          for (unsigned char I = msgStruct->self->pointer; msgStruct->gameCtxtStruct->userName[I]; I++)
            msgStruct->gameCtxtStruct->userName[I] = msgStruct->gameCtxtStruct->userName[I + 1];
          msgStruct->self->textSize -= 1;
        }
        break;
      case 113://LeftArrow key case
        if (!msgStruct->self->pointer)
          beep(1000,100);
        else
          msgStruct->self->pointer -= 1;
        break;
      case 114://RightArrow key case
        if (msgStruct->self->pointer<msgStruct->self->textSize)
          msgStruct->self->pointer+=1;
        else
          beep(1000,100);
        break;
      case 66://Caps_lock key case
      case 62://left shift key case
      case 50://right shift key case
        beep(1000,100);
        break;
      case 119://canc key case
        if (msgStruct->self->pointer < msgStruct->self->textSize)
        {
          for (unsigned char I = msgStruct->self->pointer; msgStruct->gameCtxtStruct->userName[I]; I++)
            msgStruct->gameCtxtStruct->userName[I] = msgStruct->gameCtxtStruct->userName[I + 1];
          msgStruct->self->textSize -= 1;
        }
        else
          beep(1000,100);
        break;
      default:
        if (msgStruct->self->textSize == msgStruct->self->max)
          beep(1000,100);
        else
        {
          msgStruct->self->textSize += 1;
          for(unsigned char I = msgStruct->self->textSize; I>msgStruct->self->pointer; I--)
            msgStruct->gameCtxtStruct->userName[I] = msgStruct->gameCtxtStruct->userName[I - 1];
          msgStruct->gameCtxtStruct->userName[msgStruct->self->pointer] = trueKey;
          msgStruct->self->pointer += 1;
        }
        break;
    }
    XClearWindow(msgStruct->self->root->root->display, msgStruct->self->id);
    XDrawString(
      msgStruct->self->root->root->display,
      msgStruct->self->id,
      msgStruct->self->graphicId,
      msgStruct->self->text.x,
      msgStruct->self->text.y,
      msgStruct->gameCtxtStruct->userName,
      msgStruct->self->textSize
    );
  };

  this->root->root->subWindows.push(this->id);
}

formTextBox::~formTextBox()
{
  this->root->root->subWindows.remove(this->id);
  XFreeGC(this->root->root->display,this->graphicId);
}

int formTextBox::show(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->root->display, this->id);
#endif
}

int formTextBox::hide(unsigned int microseconds)
{
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->root->display, this->id);
#endif
}