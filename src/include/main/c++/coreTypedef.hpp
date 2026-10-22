#ifndef coreTypedefHpp
#define coreTypedefHpp
#if defined __WIN32||defined __WIN64
#include <windows.h>
typedef HWND windowType;
#elifdef WaylandEnabled
#include <wayland-client.h>
typedef wayland_display displayConnection;
typedef wayland_window windowType;
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include "../../lib/c/audio/beep.h"
#include "../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
#include "../../lib/c++/DSA/algorithms/arrays.hpp"
#include "../../main/c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
typedef Display displayConnection;
typedef Window windowType;
class application;
class widget;
#endif
#endif