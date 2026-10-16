#ifndef mainWindowHpp
#define mainWindowHpp
#include "mainApplication.hpp"
#include "widget.hpp"
#include "../c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
#include "../c/generalPurposeMaskBits.h"
#if !(defined __WIN32 && defined __WIN64)
typedef
#ifdef WaylandEnabled
struct wl_display
#else
Display
#endif
graphicDisplay;
#endif

class mainScreenButton;

class window : public widget
{
  public:
    struct
    {
      unsigned long color : 24 = 0,
                    *pixelMap;
      unsigned int x = 0,
                   y = 0;
      int width =  0,
          height = 0;
    }
    icon;
    window(mainApplication *mainApplication);
    ~window();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};
#endif