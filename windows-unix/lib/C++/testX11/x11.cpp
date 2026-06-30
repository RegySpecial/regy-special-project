#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include"../../../include/C++/DSA/dataStructures/dynamicArrays.hpp"
namespace x11{
  class display{
    public:
      Display*nativeHandle;
      int screenNumber,
          depth;
      Window rootWindow;
      Screen*screen;
      XVisualInfo visualInfo;
      char*displayName;
      int connectionNumber;
      display(char*displayName){
        this->displayName=displayName;
        this->nativeHandle=XOpenDisplay(this->displayName);
        this->connectionNumber=XConnectionNumber(this->nativeHandle);
        this->screenNumber=XDefaultScreen(this->nativeHandle);
        this->screen=XScreenOfDisplay(this->nativeHandle,this->screenNumber);
        this->rootWindow=XRootWindow(this->nativeHandle,this->screenNumber);
      }
      void unlock(){
        XUnlockDisplay(this->nativeHandle);
      }
      void lock(){
        XLockDisplay(this->nativeHandle);
      }
      ~display(){
        XCloseDisplay(this->nativeHandle);
      }
      int nextEvent(XEvent*event){
        return XNextEvent(this->nativeHandle,event);
      }
      void flush(){
        XFlush(this->nativeHandle);
      }
  };
  class window{
    public:
      Window id;
      x11::display*display;
      unsigned int x,y,width,height;
      int gravity=1;
      struct{
        unsigned long color:24=0;
      }background;
      struct{
        unsigned long color:24=0;
        unsigned int width=1;
      }border;
      long propertyMask=0,
                   eventMask=0,
                   doNotPropagateMask=0;
      
      window(x11::display*display){
        this->display=display;
        XSetWindowAttributes windowAttributes={
          .background_pixel=this->background.color,
          .win_gravity=this->gravity,
          .event_mask=this->eventMask,
          .do_not_propagate_mask=this->doNotPropagateMask,
        };
        this->id=XCreateWindow(
          this->display->nativeHandle,
          this->display->rootWindow,
          this->x,
          this->y,
          this->width,
          this->height,
          this->border.width,
          this->display->visualInfo.depth,
          this->display->visualInfo.c_class,
          this->display->visualInfo.visual,
          this->propertyMask,
          &windowAttributes
        );
      }
      int selectInput(long eventMask){
        this->eventMask=eventMask;
        return XSelectInput(this->display->nativeHandle,this->id,this->eventMask);
      }
      int checkEvent(long eventMask){
        XEvent event;
        return XCheckWindowEvent(this->display->nativeHandle,this->id,eventMask,&event);
      }
      ~window(){
        XDestroySubwindows(this->display->nativeHandle,this->id);
        XDestroyWindow(this->display->nativeHandle,this->id);
      }
  };
  class cursor{
    public:
      x11::display*display;
      Cursor id;
      unsigned int shape;
      cursor(x11::display*display,unsigned char type,unsigned int shape){
        this->display=display;
        this->id=XCreateFontCursor(this->display->nativeHandle,shape);
      }
      ~cursor(){
        XFreeCursor(this->display->nativeHandle,this->id);
      }
  };
  typedef union{
    x11::window*window;
    x11::cursor*cursor;
  }drawable;
  class graphicContext{
    public:
      GC id;
      Font font;
      unsigned long background:24,
                    foreground:24;
      x11::window*window;
      unsigned int propertyMask=0;
      graphicContext(x11::window*window){
        this->window=window;
        XGCValues gcValues;
        this->id=XCreateGC(window->display->nativeHandle,this->window->id,this->propertyMask,&gcValues);
      }
      inline void flush(){
        XFlushGC(this->window->display->nativeHandle,this->id);
      }
      ~graphicContext(){
        XFreeGC(this->window->display->nativeHandle,this->id);
      }
  };
  class pixmap{
    public:
      x11::drawable*drawable;
  };
}