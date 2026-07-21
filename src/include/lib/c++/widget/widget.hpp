#ifndef widgetHpp
#define widgetHpp
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../windowRoles.h"
#if defined __WIN32 || defined __WIN64
#define windowId HWND
#else
#define windowId Window
#endif
class widget{
public:
  widget*root;
  windowId id;
  #if !(defined __WIN32 && defined __WIN64)
  Display*display;
  #endif
  unsigned int x=0,y=0,width=500,height=500;
  struct{
    unsigned long color:24=0,
                  **pixelMap;
    unsigned int x=0,y=0,width=500,height=500;
  }background;
  struct{
    unsigned long color:24=0xffffff;
  }foreground;
  const char*title;
  struct{
    const char*family;
    unsigned int size,weight;
  }font;
  struct{
    unsigned char style;
    unsigned int width;
    unsigned long color:24=0xffffff;
  }border;
  long eventMask=0,
       dontPropagateMask=0;
};
#endif