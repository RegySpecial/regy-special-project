#ifndef mainWindowHpp
#define mainWindowHpp
#include "application.hpp"
#include "widget.hpp"
#include "../c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
#include "../c/generalPurposeMaskBits.h"

class icon
{
  public:
    unsigned long color : 24 = 0,
                  *pixelMap;
    unsigned int x = 0,
                 y = 0;
    int width =  0,
        height = 0;
};

class mainScreenButton;

class window : public widget
{
  public:
    icon *icon;
    window(application *app, const char *title);
    ~window();
    bool addEventListener(unsigned char eventState, void (*listener)(event *event, window *target, void *extraArguments));
    bool removeEventListener(unsigned char eventState);
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};
#endif