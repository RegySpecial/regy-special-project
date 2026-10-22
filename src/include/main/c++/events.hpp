#ifndef eventsH
#define eventsH
#include "coreTypedef.hpp"

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
    unsigned char state;
    application *app;
    widget *target;
    bool propagation;
};

class mouseEvent
: event
{
  public:
    unsigned button;
    int x,
        y;
};

class pointerEvent
: event
{
  public:
    int x,
        y;
};

class windowEvent
: event
{
  public:
    int x,
        y;
    unsigned int width,
                 height;
};

class keyboardEvent
: event
{
  public:
    unsigned char key;
    unsigned char specialKeyMask;
};
#endif