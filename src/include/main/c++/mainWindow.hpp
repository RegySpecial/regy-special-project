#ifndef mainWindowHpp
#define mainWindowHpp
#if !(defined __WIN32 && defined __WIN64)
#ifdef WaylandEnabled
#define graphicDisplay wayland_display
#else
#define graphicDisplay Display
#endif
#endif
#include "commonWidgetInterface.hpp"

class mainWindow:public commonWidgetInterface{
public:
  struct
  {
    unsigned long color : 24 = 0,
                  *pixelMap;
    unsigned int x = 0,
                 y = 0;
    int width = 0,
        height = 0;
  } icon;
  #if defined __WIN32 || defined __WIN64
  HINSTANCE hInst, hInstPrev;
  char* cmdline;
  int cmdshow;
  mainWindow(HINSTANCE hInst, HINSTANCE hInstPrev, char* cmdline, int cmdshow);
  #else
  int argc;
  char**argv,
      **envp;
  graphicDisplay *display;
  XVisualInfo visualInfo={.c_class=InputOutput};    
  mainWindow(int argc,char*argv[],char*envp[],const char*title);
  #endif
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
