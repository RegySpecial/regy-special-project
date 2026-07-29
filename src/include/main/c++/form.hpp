#ifndef formHpp
#define formHpp
#include"mainWindow.hpp"
class form:public commonWidgetInterface{
public:
  mainWindow*root;
  form(mainWindow*root);
  ~form();
  int show(unsigned int microseconds) override;
  int hide(unsigned int microseconds) override;
  void onClientMessage(XClientMessageEvent*event,void*extraArgs) override;
  void onResize(XResizeRequestEvent*event,void*extraArgs) override;
  void onButtonUp(XButtonReleasedEvent*event,void*extraArgs) override;
  void onButtonDown(XButtonPressedEvent*event,void*extraArgs) override;
  void onKeyUp(XKeyReleasedEvent*event,void*extraArgs) override;
  void onKeyDown(XKeyPressedEvent*event,void*extraArgs) override;
  void onExpose(XExposeEvent*event,void*extraArgs) override;
};
#endif
