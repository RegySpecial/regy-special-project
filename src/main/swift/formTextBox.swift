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
}

formTextBox::~formTextBox(){
  XFreeGC(this->root->root->display,this->graphicId);
}

void formTextBox::onKeyDown(XKeyPressedEvent*event,void*extraArgs){
  gameContextStructure*gameCtxtStruct=(gameContextStructure*)extraArgs;
  char trueKey=(char)XkbKeycodeToKeysym(
    this->root->root->display,//X display
    event->keycode,//key event key code
    0,//key group
    readBit<unsigned char>(event->state,ShiftMapIndex)^
    readBit<unsigned char>(event->state,LockMapIndex)//key level
  );
  //Mod2=Alt
  switch(event->keycode){
    case 22://Backspace key case
      if(this->pointer==0)
        beep(1000,100);
      else{
        this->pointer-=1;
        for(unsigned char I=this->pointer;gameCtxtStruct->userName[I];I++)
          gameCtxtStruct->userName[I]=gameCtxtStruct->userName[I+1];
        this->textSize-=1;
      }
      break;
    case 113://LeftArrow key case
      if(this->pointer==0)beep(1000,100);
      else this->pointer-=1;
      break;
    case 114://RightArrow key case
      if(this->pointer<this->textSize)this->pointer+=1;
      else beep(1000,100);
      break;
    case 66://Caps_lock key case
    case 62://left shift key case
    case 50://right shift key case
      beep(1000,100);
      break;
    case 119://canc key case
      if(this->pointer<this->textSize){
        for(unsigned char I=this->pointer;gameCtxtStruct->userName[I]!=0;I++)
          gameCtxtStruct->userName[I]=gameCtxtStruct->userName[I+1];
        this->textSize-=1;
      }else
        beep(1000,100);
      break;
    default:
      if(this->textSize==40)
        beep(1000,100);
      else{
        this->textSize+=1;
        for(unsigned char I=this->textSize;I>this->pointer;I--)
          gameCtxtStruct->userName[I]=gameCtxtStruct->userName[I-1];
        gameCtxtStruct->userName[this->pointer]=trueKey;
        this->pointer+=1;
      }
      break;
  }
  XClearWindow(this->root->root->display,this->id);
  XDrawString(
    this->root->root->display,
    this->id,
    this->graphicId,
    20,
    20,
    gameCtxtStruct->userName,
    this->textSize
  );
}