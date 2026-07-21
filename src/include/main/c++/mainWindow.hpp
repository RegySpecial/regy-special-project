#ifndef mainWindowHpp
#define mainWindowHpp
#include "commonWidgetInterface.hpp"
class mainWindow:public commonWidgetInterface{
public:
  Display*display;
  XVisualInfo visualInfo={.c_class=InputOutput};
  mainWindow(const char*title);
  mainWindow(unsigned int x,unsigned int y,int width,int height);
  mainWindow(const char*title,unsigned int x,unsigned int y,int width,int height);
  mainWindow(int argc,char*argv[],char*envp[],const char*title);
  mainWindow(int argc,char*argv[],char*envp[],unsigned int x,unsigned int y,int width,int height);
  mainWindow(int argc,char*argv[],char*envp[],const char*title,unsigned int x,unsigned int y,int width,int height);
  void onresize(XEvent*event,void*extraArgs);
  void onclientmessage(XEvent*event,void*extraArgs);
  ~mainWindow();
};
#endif