#ifndef eventsH
#define eventsH
#include "../coreTypedef.hpp"

#if defined __cplusplus||defined c_plusplus
extern "C" {
#endif
  typedef enum
  : unsigned char
  {
  #if defined __WIN32||defined __WIN64
  #else
    eventState_keyDown = 2,
  #endif
    eventState_keyUp,
    eventState_mouseDown,
    eventState_mouseUp,
    eventState_move,
    eventState_enter,
    eventState_leave,
    eventState_focus, 
    eventState_blur,
    eventState_keyMap,
    eventState_view,
    eventState_graphicShow,
    eventState_unview,
    eventState_visible,
    eventState_create,
    eventState_destroy,
    eventState_hide,
    eventState_show,
    eventState_askShow,
    eventState_reparent,
    eventState_config,
    eventState_askConfig,
    eventState_gravity,
    eventState_resize,
    eventState_circulate,
    eventState_askCirculate,
    eventState_property,
    eventState_unselect,
    eventState_askSelect, 
    eventState_select,
    eventState_colorMap,
    eventState_message,
    eventState_showing,
    eventState_event,
    eventState_lastEvent
  }
  eventState;
#if defined __cplusplus||defined c_plusplus
}
#endif

class event
{
  public:
    eventState state;
    application *app;
    widget *target;
    bool propagation;
    event(widget *target, eventState state);
};

class mouseEvent
: event
{
  public:
    unsigned int button;
    int x,
        y;
    mouseEvent(widget *target, eventState state);
};

class pointerEvent
: event
{
  public:
    int x,
        y;
    pointerEvent(widget *target, eventState state);
};

class widgetEvent
: event
{
  public:
    int x,
        y;
    unsigned int width,
                 height;
    widgetEvent(widget *target, eventState state);
};

class keyboardEvent
: event
{
  public:
    unsigned char key,
                  specialKeyMask;
    keyboardEvent(widget *target, eventState state);
};

class selectionEvent
: event
{
  public:
    unsigned long long x,
                       y,
                       width,
                       height,
                       textStart,
                       textEnd;
    char *textSelected;
    selectionEvent(widget *target, eventState state);
};

class focusEvent
: event
{
  public:
    focusEvent(widget *target, eventState state);
};
#endif