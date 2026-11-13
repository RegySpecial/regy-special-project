#ifndef mainWindowHpp
#define mainWindowHpp
#include "../application/application.hpp"
#include "widget.hpp"
#include "../../../../main/c/manageArguments.h"
#include "../../bitManipulation.hpp"
#include "../../../../main/c/generalPurposeMaskBits.h"
#include "image.hpp"

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
    bool addEventListener(eventState eventId, void (*listener)(event *eventClass, widget *target, void *extraArguments)) override;
    bool removeEventListener(eventState eventId) override;
    bool show(unsigned int microseconds) override;
    bool hide(unsigned int microseconds) override;
};
#endif