#include "../../include/main/c++/formTextBox.hpp"

formTextBox::formTextBox(form*root){
  XSetWindowAttributes formTextBoxAttributes={
    .background_pixel=(self.background.color=0),
    .border_pixel=(self.border.color=255<<8),
    .event_mask=(self.eventMask=KeyPressMask|FocusChangeMask|EnterWindowMask|LeaveWindowMask),
    .do_not_propagate_mask=(self.dontPropagateMask=KeyPressMask)
  };
  self.root=root;
  self.id=XCreateWindow(
    self.root.root.display,
    self.root.id,
    (self.x=self.root.width*5/100),
    (self.y=self.root.height*5/100),
    (self.width=self.root.width-2*(self.root.width*10/100)),
    (self.height=self.root.height*20/100),
    (self.border.width=1),
    self.root.root.visualInfo.depth,
    self.root.root.visualInfo.c_class,
    self.root.root.visualInfo.visual,
    self.attributeMask=(CWBackPixel|CWBorderWidth|CWBorderPixel|CWEventMask|CWDontPropagate),
    &formTextBoxAttributes
  );
  XGCValues gcValues={
    .foreground=(self.text.color=255<<8)
  };
  self.graphicId=XCreateGC(
    self.root.root.display,
    self.id,
    GCForeground,
    &gcValues
  );
}

formTextBox::~formTextBox(){
  XFreeGC(self.root.root.display,self.graphicId);
}

void formTextBox::onKeyDown(XKeyPressedEvent*event,void*extraArgs){
  gameContextStructure*gameCtxtStruct=(gameContextStructure*)extraArgs;
  char trueKey=(char)XkbKeycodeToKeysym(
    self.root.root.display,//X display
    event.keycode,//key event key code
    0,//key group
    readBit<unsigned char>(event.state,ShiftMapIndex)^
    readBit<unsigned char>(event.state,LockMapIndex)//key level
  );
  //Mod2=Alt
  switch(event.keycode){
    case 22://Backspace key case
      if(self.pointer==0)
        beep(1000,100);
      else{
        self.pointer-=1;
        for(unsigned char I=self.pointer;gameCtxtStruct.userName[I];I++)
          gameCtxtStruct.userName[I]=gameCtxtStruct.userName[I+1];
        self.textSize-=1;
      }
      break;
    case 113://LeftArrow key case
      if(self.pointer==0)beep(1000,100);
      else self.pointer-=1;
      break;
    case 114://RightArrow key case
      if(self.pointer<self.textSize)self.pointer+=1;
      else beep(1000,100);
      break;
    case 66://Caps_lock key case
    case 62://left shift key case
    case 50://right shift key case
      beep(1000,100);
      break;
    case 119://canc key case
      if(self.pointer<self.textSize){
        for(unsigned char I=self.pointer;gameCtxtStruct.userName[I]!=0;I++)
          gameCtxtStruct.userName[I]=gameCtxtStruct.userName[I+1];
        self.textSize-=1;
      }else
        beep(1000,100);
      break;
    default:
      if(self.textSize==40)
        beep(1000,100);
      else{
        self.textSize+=1;
        for(unsigned char I=self.textSize;I>self.pointer;I--)
          gameCtxtStruct.userName[I]=gameCtxtStruct.userName[I-1];
        gameCtxtStruct.userName[self.pointer]=trueKey;
        self.pointer+=1;
      }
      break;
  }
  XClearWindow(self.root.root.display,self.id);
  XDrawString(
    self.root.root.display,
    self.id,
    self.graphicId,
    20,
    20,
    gameCtxtStruct.userName,
    self.textSize
  );
}