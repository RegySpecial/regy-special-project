#ifndef commonWidgetInterfaceHpp
#define commonWidgetInterfaceHpp
#if defined __WIN32||defined __WIN64
#include <windows.h>
#elifdef WaylandEnabled
#include <wayland-client.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../../lib/c/audio/beep.h"
#include "../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include "../../lib/c++/DSA/algorithms/arrays.hpp"
#include "../../main/c/manageArguments.h"
#endif
class commonWidgetInterface{
  public:
    unsigned int x=0,
                 y=0;
    int width=0,
        height=0;
    const char*title;
    Window id=0;
    dynamicArray<Window>subWindows;
    struct{
      unsigned int width=1;
      unsigned long color:24=0xffffff;
    }border;
    struct{
      unsigned long color:24=0;
    }background;
    long attributeMask=CWBorderWidth|CWBackPixel|CWBorderPixel|CWEventMask,
         eventMask=ExposureMask|ResizeRedirectMask|StructureNotifyMask,
         dontPropagateMask=0;
};
#endif