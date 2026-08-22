#ifndef mainWindowHpp
#define mainWindowHpp
#include "commonWidgetInterface.hpp"

class mainWindow:public commonWidgetInterface{
public:
  Display*display;
  XVisualInfo visualInfo={.c_class=InputOutput};
  int argc;
  char**argv,
      **envp;
  mainWindow(int argc,char*argv[],char*envp[],const char*title);
  ~mainWindow();
  int show(unsigned int microseconds) override;
  int hide(unsigned int microseconds) override;
  void onClientMessage(XClientMessageEvent*event,void*extraArgs) override;
  void onResize(XResizeRequestEvent*event,void*extraArgs) override;
  void onButtonUp(XButtonReleasedEvent*event,void*extraArgs) override;
  void onButtonDown(XButtonPressedEvent*event,void*extraArgs) override;
  void onKeyUp(XKeyReleasedEvent*event,void*extraArgs) override;
  void onKeyDown(XKeyPressedEvent*event,void*extraArgs) override;
  void onExpose(XExposeEvent*event,void*extraArgs) override;
  void onPointerIn(XEnterWindowEvent*event,void*extraArgs) override;
  void onPointerOut(XLeaveWindowEvent*event,void*extraArgs) override;
  void onPointerMove(XMotionEvent*event,void*extraArgs) override;
  void onFocusIn(XFocusInEvent*event,void*extraArgs) override;
  void onFocusOut(XFocusOutEvent*event,void*extraArgs) override;
  void onAny(XAnyEvent*event,void*extraArgs) override;
};
#endif
