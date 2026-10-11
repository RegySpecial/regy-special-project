#ifndef mainApplicationHpp
#define mainApplicationHpp

#if defined __WIN32||defined __WIN64
#include <windows.h>
typedef HWND windowIdentifier;
#elifdef WaylandEnabled
#include <wayland-client.h>
typedef wayland_display displayConnection;
typedef wayland_window windowIdentifier;
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include "../../lib/c/audio/beep.h"
#include "../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include "../../lib/c++/DSA/algorithms/arrays.hpp"
#include "../../main/c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
typedef Window windowIdentifier;
typedef Display displayConnection;
#endif

class mainApplication
{
  public:
    #if defined __WIN32 || defined __WIN64
    HINSTANCE hInst,
              hInstPrev;
    char *cmdline;
    int cmdshow;
    mainApplication(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow);
    #else
    int argc;
    char
      **argv,
      **envp;
    gameContextStructure gameContextContainer;
    displayConnection *display;
    #ifndef waylandEnabled
    Screen *screen;
    #endif
    mainApplication(int argc, char **argv, char **envp);
    ~mainApplication();
    void eventLoop(unsigned int microseconds);
    #endif
};
#endif