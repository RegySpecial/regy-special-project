#ifndef windowHpp
#define windowHpp
#include"drawable.hpp"
namespace x11{
  class window:public drawable{
    public:
      long eventMask;
      const char*title,*icon;
      window(x11::display*display);
      int selectInput(long eventMask);
      int checkEvent(long eventMask,XEvent*event);
      int sendEvent(bool propagation,long eventMask,XEvent*eventSend);
      int setStandardProperties(const char*windowName,const char*windowIcon,Pixmap iconPixmap,char**argv,int argc,XSizeHints*hints);
      int map(unsigned int microseconds);
      int mapRaised(unsigned int microseconds);
      ~window();
  };
}
#endif