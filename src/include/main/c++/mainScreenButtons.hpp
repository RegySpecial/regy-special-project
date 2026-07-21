#include "mainWindow.hpp"
#include "mainDialogs.hpp"
class mainScreenButton:public commonWidgetInterface{
  public:
    mainWindow*root;
    mainScreenButton(mainWindow*root,const char*text);
    void onclick(XEvent*event,void*extraArgs);
};