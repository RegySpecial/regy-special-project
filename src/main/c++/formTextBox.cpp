#include "../../include/main/c++/formTextBox.hpp"

formTextBox::formTextBox(form*root){
  XSetWindowAttributes formTextBoxAttributes={
    .background_pixel=(this->background.color=0),
    .border_pixel=(this->border.color=255<<8),
    .event_mask=(this->eventMask=KeyPressMask|FocusChangeMask|EnterWindowMask|LeaveWindowMask),
    .do_not_propagate_mask=(this->dontPropagateMask=KeyPressMask)
  };
  this->root=root;
  this->id=XCreateWindow(
    this->root->root->display,
    this->root->id,
    (this->x=this->root->width*5/100),
    (this->y=this->root->height*5/100),
    (this->width=this->root->width-2*(this->root->width*10/100)),
    (this->height=this->root->height*20/100),
    (this->border.width=1),
    this->root->root->visualInfo.depth,
    this->root->root->visualInfo.c_class,
    this->root->root->visualInfo.visual,
    this->attributeMask=(CWBackPixel|CWBorderWidth|CWBorderPixel|CWEventMask|CWDontPropagate),
    &formTextBoxAttributes
  );
  XGCValues gcValues={
    .foreground=(this->text.color=255<<8)
  };
  this->graphicId=XCreateGC(
    this->root->root->display,
    this->id,
    GCForeground,
    &gcValues
  );

  this->onKeyDown = [](XKeyPressedEvent*event,void*extraArgs){
    struct messageStructure
    {
      gameContextStructure *gameCtxtStruct;
      formTextBox *self;
    };

    struct messageStructure* msgStruct = (messageStructure*) extraArgs;
    char trueKey=(char)XkbKeycodeToKeysym(
      msgStruct->self->root->root->display,//X display
      event->keycode,//key event key code
      0,//key group
      readBit<unsigned char>(event->state,ShiftMapIndex)^
      readBit<unsigned char>(event->state,LockMapIndex)//key level
    );
    //Mod2=Alt
    switch(event->keycode){
      case 22://Backspace key case
        if (!msgStruct->self->pointer)
          beep(1000,100);
        else{
          msgStruct->self->pointer-=1;
          for(unsigned char I=msgStruct->self->pointer;msgStruct->gameCtxtStruct->userName[I];I++)
            msgStruct->gameCtxtStruct->userName[I]=msgStruct->gameCtxtStruct->userName[I+1];
          msgStruct->self->textSize-=1;
        }
        break;
      case 113://LeftArrow key case
        if(msgStruct->self->pointer==0)beep(1000,100);
        else msgStruct->self->pointer-=1;
        break;
      case 114://RightArrow key case
        if(msgStruct->self->pointer<msgStruct->self->textSize)msgStruct->self->pointer+=1;
        else beep(1000,100);
        break;
      case 66://Caps_lock key case
      case 62://left shift key case
      case 50://right shift key case
        beep(1000,100);
        break;
      case 119://canc key case
        if(msgStruct->self->pointer<msgStruct->self->textSize){
          for(unsigned char I=msgStruct->self->pointer;msgStruct->gameCtxtStruct->userName[I];I++)
            msgStruct->gameCtxtStruct->userName[I]=msgStruct->gameCtxtStruct->userName[I+1];
          msgStruct->self->textSize-=1;
        }else
          beep(1000,100);
        break;
      default:
        if(msgStruct->self->textSize==msgStruct->self->max)
          beep(1000,100);
        else{
          msgStruct->self->textSize+=1;
          for(unsigned char I=msgStruct->self->textSize;I>msgStruct->self->pointer;I--)
            msgStruct->gameCtxtStruct->userName[I]=msgStruct->gameCtxtStruct->userName[I-1];
          msgStruct->gameCtxtStruct->userName[msgStruct->self->pointer]=trueKey;
          msgStruct->self->pointer+=1;
        }
        break;
    }
    XClearWindow(msgStruct->self->root->root->display,msgStruct->self->id);
    XDrawString(
      msgStruct->self->root->root->display,
      msgStruct->self->id,
      msgStruct->self->graphicId,
      20,
      20,
      msgStruct->gameCtxtStruct->userName,
      msgStruct->self->textSize
    );
  };
}

formTextBox::~formTextBox(){
  XFreeGC(this->root->root->display,this->graphicId);
}

int formTextBox::show(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_NORMAL);
#else
  usleep(microseconds);
  return XMapRaised(this->root->root->display,this->id);
#endif
}
int formTextBox::hide(unsigned int microseconds){
#if defined __WIN32 || defined __WIN64
  Sleep(microseconds);
  return ShowWinodw(this->id, SW_HIDE);
#else
  usleep(microseconds);
  return XUnmapWindow(this->root->root->display,this->id);
#endif
}