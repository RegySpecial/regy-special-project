#ifndef widgetHpp
#define widgetHpp
#include "application.hpp"

class widget
{
  protected:
    windowType id;
    GC graphicId = 0;
    long attributeMask =     0,
         eventMask =         ExposureMask | ResizeRedirectMask | StructureNotifyMask,
         dontPropagateMask = 0,
         graphicMask =       0;
  public:
    unsigned int x = 0,
                 y = 0;
    int width =  0,
        height = 0;
    const char *title;
    application *app;
    dynamicArray<widget> subwidget;
    widget *parent;
    struct
    {
      unsigned int width = 1;
      unsigned long color : 24 = 0xffffff;
    }
    border;
    struct
    {
      unsigned long color : 24 = 0,
                    *pixelMap;
      unsigned int x = 0,
                   y = 0;
      int width =  0,
          height = 0;
    }
    background;
    struct
    {
      const char *value;
      unsigned int x = 0,
                   y = 0;
      unsigned long color : 24 = 0;
      struct
      {
        const char *family;
        unsigned int size,
                     weight;
      }
      font;
    }
    text;

    virtual bool show(unsigned int microseconds) = 0;
    virtual bool hide(unsigned int microseconds) = 0;
    virtual bool addEventListener(eventState eventId, void (*listener)(event *eventClass, widget *target, void *extraArguments)) = 0;
    virtual bool removeEventListener(eventState eventId) = 0;
};
#endif
