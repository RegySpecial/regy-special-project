#ifndef commonWidgetInterfaceHpp
#define commonWidgetInterfaceHpp
#if defined __WIN32||defined __WIN64
#include <windows.h>
#define window HWND
#elifdef WaylandEnabled
#include <wayland-client.h>
#define window wayland_window
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include "../../lib/c/audio/beep.h"
#include "../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include "../../lib/c++/DSA/algorithms/arrays.hpp"
#include "../../main/c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
#define window Window
#endif

class commonWidgetInterface{
  public:
    unsigned int x = 0,
                 y = 0;
    int width = 0,
        height = 0;
    const char *title;
    window id = 0;
    GC graphicId = 0;
    dynamicArray<window> subWindows;
    struct{
      unsigned int width = 1;
      unsigned long color : 24 = 0xffffff;
    }border;
    struct{
      unsigned long color : 24 = 0,
                    *pixelMap;
      unsigned int x = 0,
                   y = 0;
      int width = 0,
          height = 0;
    }background;
    struct{
      const char *value;
      unsigned int x = 0,
                   y = 0;
      int width = 0,
          height = 0;
      unsigned long color : 24 = 0;
      struct{
        const char *family;
        unsigned int size,
                     weight;
      }font;
    }text;
    long attributeMask =     0,
         eventMask =         ExposureMask | ResizeRedirectMask | StructureNotifyMask,
         dontPropagateMask = 0,
         graphicMask =       0;

    virtual int show(unsigned int microseconds) = 0;
    virtual int hide(unsigned int microseconds) = 0;

    void (*onClientMessage)(XClientMessageEvent*event,void*extraArgs);
    void (*onResize)(XResizeRequestEvent*event,void*extraArgs);
    void (*onButtonUp)(XButtonReleasedEvent*event,void*extraArgs);
    void (*onButtonDown)(XButtonPressedEvent*event,void*extraArgs);
    void (*onKeyUp)(XKeyReleasedEvent*event,void*extraArgs);
    void (*onKeyDown)(XKeyPressedEvent*event,void*extraArgs);
    void (*onExpose)(XExposeEvent*event,void*extraArgs);
    void (*onPointerIn)(XEnterWindowEvent*event,void*extraArgs);
    void (*onPointerOut)(XLeaveWindowEvent*event,void*extraArgs);
    void (*onPointerMove)(XMotionEvent*event,void*extraArgs);
    void (*onFocusIn)(XFocusInEvent*event,void*extraArgs);
    void (*onFocusOut)(XFocusOutEvent*event,void*extraArgs);
    void (*onAny)(XAnyEvent*event,void*extraArgs);
};
#endif
