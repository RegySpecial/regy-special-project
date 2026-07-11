#if defined __WIN32||defined __WIN64
#include<windows.h>
#elifdef WaylandEnabled
#include<wayland-client.h>
#else
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include"../../lib/c/audio/beep.h"
#include"../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#endif
class mainWindow{
  unsigned int x=0,
               y=0;
  int width=([]()->int{ 
        Display*display=XOpenDisplay(NULL);
        int screenNumber=XDefaultScreen(display);
        Screen*screen=XScreenOfDisplay(display,screenNumber);
        XCloseDisplay(display);
        return screen->width;
      })(),
      height=([]()->int{ 
        Display*display=XOpenDisplay(NULL);
        int screenNumber=XDefaultScreen(display);
        Screen*screen=XScreenOfDisplay(display,screenNumber);
        XCloseDisplay(display);
        return screen->height;
      })();
  char*title;
  Display*display;
  Window id;
  dynamicArray<Window>subWindows;
  struct{
    unsigned int width=1;
    unsigned long color:24=0;
  }border;
  struct{
    unsigned long color:24=0;
  }background;
  unsigned long attributeMask;
  mainWindow(const char*title);
  mainWindow(unsigned int x,unsigned int y,int width,int height);
  mainWindow(const char*title,unsigned int x,unsigned int y,int width,int height);
  mainWindow(int argc,char*argv[],char*envp[],const char*title);
  mainWindow(int argc,char*argv[],char*envp[],unsigned int x,unsigned int y,int width,int height);
  mainWindow(int argc,char*argv[],char*envp[],const char*title,unsigned int x,unsigned int y,int width,int height);
  void onresize(mainWindow*target,XEvent*event);
  void onclientmessage(mainWindow*target,XEvent*event);
  ~mainWindow();
};