#ifndef formTextBoxHpp
#define formTextBoxHpp
#include "form.hpp"
class formTextBox:public commonWidgetInterface{
public:
  form*root;
	unsigned char pointer=0,
	              min=1,
	              max=40,
								textSize=0;
  formTextBox(form*root);
  ~formTextBox();
  int show(unsigned int microseconds);
  int hide(unsigned int microseconds);
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