#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<X11/XKBlib.h>
#include<math.h>
#include<unistd.h>
#include<signal.h>
typedef struct{
  int x,y;
  unsigned int width,height;
}Coordinates;

int main(int argc,char*argv[]) {
  Display* display = XOpenDisplay(NULL);
  if(display==NULL) {
    std::cerr << "Failed to open display\n";
    return 1;
  }
  int screenNumber = XDefaultScreen(display);
  
  // Ottieni il visual predefinito e il suo depth corrispondente
  Visual* visual = XDefaultVisual(display, screenNumber);
  int depth = XDefaultDepth(display, screenNumber);
  
  // Verifica che il visual sia valido per il depth
  if(visual==NULL) {
    std::cerr << "Failed to get default visual\n";
    XCloseDisplay(display);
    return 1;
  }
  Window window,
         form,
         textBox,
         submitButton;
  
  Screen* screen = XScreenOfDisplay(display, screenNumber);
  
  XSetWindowAttributes windowAttributes,
                       formAttributes,
                       textBoxAttributes,
                       submitButtonAttributes;

  windowAttributes.background_pixel = 0xff0000;
  windowAttributes.event_mask=ExposureMask;

  formAttributes.background_pixel = 0x808080;
  formAttributes.border_pixel = 0xffffff;

  textBoxAttributes.background_pixel=0xffffff;
  textBoxAttributes.border_pixel=0x00ffff;
  textBoxAttributes.event_mask=KeyPressMask;
  textBoxAttributes.do_not_propagate_mask=KeyPressMask;
  
  submitButtonAttributes.background_pixel=0xffffff;
  submitButtonAttributes.border_pixel=0;
  submitButtonAttributes.event_mask=ExposureMask|ButtonPressMask;
  submitButtonAttributes.do_not_propagate_mask=ButtonPressMask;

  Coordinates formCoordinates={
    (int)(screen->width*20/100),//20% of screen.width
    (int)(screen->height*20/100),//20% of screen.width
    (unsigned int)(screen->width-2*screen->width*20/100),//screen.width-2*form.x
    (unsigned int)(screen->height-2*screen->height*20/100)//screen.width-2*form.x
  };

  window=XCreateWindow(
    display,
    XRootWindow(display,screenNumber),
    0,
    0,
    screen->width,
    screen->height,
    0,
    depth,
    InputOutput,
    visual,
    CWBackPixel|CWEventMask,
    &windowAttributes
  );
  form=XCreateWindow(
    display,
    window,
    formCoordinates.x,//20% of screen.width
    formCoordinates.y,//20% of screen.width
    formCoordinates.width,//screen.width-2*form.x
    formCoordinates.height,//screen.width-2*form.x
    1,
    depth,
    InputOutput,
    visual,
    CWBackPixel|CWBorderPixel,
    &formAttributes
  );
  
  XWindowAttributes formAttr,textBoxAttr,submitButtonAttr;
  int getFormAttr=XGetWindowAttributes(display,form,&formAttr);
  textBox=XCreateWindow(
    display,
    form,
    formAttr.width*5/100,//20% of form.width
    formAttr.height*5/100,//20% of form.height
    formAttr.width-2*(formAttr.width*10/100),//form.width-2*textBox.x
    formAttr.height*20/100,//20% form.height
    1,
    depth,
    InputOutput,
    visual,
    CWBackPixel|CWBorderPixel|CWEventMask|CWDontPropagate,
    &textBoxAttributes
  );
  int getTextBoxAttr=XGetWindowAttributes(display,textBox,&textBoxAttr);
  submitButton=XCreateWindow(
    display,
    form,
    formAttr.width-100-10,
    formAttr.height-50-10,
    100,
    50,
    1,
    depth,
    InputOutput,
    visual,
    CWBackPixel|CWBorderPixel|CWEventMask|CWDontPropagate,
    &submitButtonAttributes
  );
  int getSubmitButtonAttr=XGetWindowAttributes(display,submitButton,&submitButtonAttr);
  if(!window){
    std::cerr << "Failed to create window\n";
    XCloseDisplay(display);
    return 1;
  }
  if(!form){
    std::cerr << "Failed to create form\n";
    XCloseDisplay(display);
    return 1;
  }
  if(!textBox){
    std::cerr << "Failed to create text box\n";
    XCloseDisplay(display);
    return 1;
  }
  if(!submitButton){
    std::cerr << "Failed to create submit button\n";
    XCloseDisplay(display);
    return 1;
  }
  XSetStandardProperties(display,window,"coso",NULL,0,argv,argc,NULL);
  XMapWindow(display,window);
  XMapSubwindows(display,window);
  XMapSubwindows(display,form);
  XEvent event;
  bool running=1;
  XGCValues textBoxTextGCValues,
            maxTextSizeGCValues;
  textBoxTextGCValues.foreground=0;
  maxTextSizeGCValues.foreground=255<<16;
  GC textBoxTextGC=XCreateGC(display,textBox,GCForeground,&textBoxTextGCValues),
     maxTextSizeGC=XCreateGC(display,form,GCForeground,&maxTextSizeGCValues),
     submitButtonGC=XCreateGC(display,submitButton,GCForeground,&textBoxTextGCValues); 
  register char text[41];
  std::cout<<window<<' '<<form<<' '<<textBox<<' '<<submitButton<<'\n';
  for(unsigned char textI=0;running;){
    XNextEvent(display,&event);
    switch(event.xany.window,event.xany.type){
      case(textBox,KeyPress):{
        char trueKey=(char)XkbKeycodeToKeysym(display,event.xkey.keycode,0,event.xkey.state&ShiftMask==1);
        //Backspace|LeftArrow|RightArrow
        unsigned char specialKeyCodes[]={22,113,114};
        text[textI]=(trueKey)*(event.xkey.keycode!=22);
        if(textI==0&&event.xkey.keycode==22||textI==40&&event.xkey.keycode!=22||event.xkey.keycode==50){
          putchar('\a');
          XClearWindow(display,form);
          XDrawString(
            display,
            form,
            maxTextSizeGC,
            formCoordinates.x,
            formCoordinates.y,
            textI==0?
              "The text box content is empty":
            event.xkey.keycode==50?
              "Shift key has been pressed":
            textI==40?
              "The text box content size has been reached!":
            "",
            textI==0
              ?29:
            event.xkey.keycode==50
              ?26:
            textI==40?
              43:
            0
          );
        }else{
          textI+=pow(-1,((event.xkey.keycode==22||event.xkey.keycode==113)&&0<=textI&&textI<=40)^(event.xkey.keycode==114));
          XClearWindow(display,textBox);
          XDrawString(
            display,
            textBox,
            textBoxTextGC,
            textBoxAttr.x,//20% of form.width
            textBoxAttr.y,//20% of form.height
            text,
            textI
          );
          XClearWindow(display,form);
          XDrawString(
            display,
            form,
            maxTextSizeGC,
            formCoordinates.x,
            formCoordinates.y,
            0,
            0
          );
        }
        std::cout<<event.xkey.keycode<<' '<<text<<'\n';
        break;
      }
      case(form,Expose):{
        XDrawString(
          display,
          form,
          maxTextSizeGC,
          formCoordinates.x,
          formCoordinates.y,
          "The text box content is empty",
          sizeof("The text box content is empty")-1
        );
        XDrawString(
          display,
          submitButton,
          submitButtonGC,
          5,
          10,
          "Invia",
          5
        );
        break;
      }
      case(submitButton,ButtonPress):{
        std::cout<<"x:"<<event.xbutton.x<<" y:"<<event.xbutton.y<<" dx:"<<(submitButtonAttr.x-event.xbutton.x)<<" dy:"<<(submitButtonAttr.y-event.xbutton.y)<<'\n';
        if(strcmp(text,"coso shish sus troio t6yf iojijo hjjhjh")==0)running=0;
        break;
      }
    }
  }
  XFreeGC(display,submitButtonGC);
  XFreeGC(display,maxTextSizeGC);
  XFreeGC(display,textBoxTextGC);
  XDestroySubwindows(display,form);
  XDestroySubwindows(display,window);
  XDestroyWindow(display,window);
  XCloseDisplay(display);
  return 0;
}