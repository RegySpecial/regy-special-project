#ifndef mainWindowHpp
#define mainWindowHpp
#include "../application/application.hpp"
#include "widget.hpp"
#include "../../../../main/c/manageArguments.h"
#include "../../../../lib/c++/bitManipulation.hpp"
#include "../../../../main/c/generalPurposeMaskBits.h"

class icon
{
  public:
    unsigned long color : 24 = 0,
                  *pixels;
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