#ifndef eventsH
#define eventsH
#include "../coreTypedef.hpp"

#if defined __cplusplus||defined c_plusplus
extern "C" {
#endif
  typedef enum
  : unsigned char
  {
    eventState_mouse_press,
    eventState_mouse_release,
    eventState_pointer_in,
    eventState_pointer_out,
    eventState_pointer_move,
    eventState_widget_create,
    eventState_widget_destroy,
    eventState_widget_move,
    eventState_widget_resize,
    eventState_widget_show,
    eventState_widget_hide,
    eventState_window_close,
    eventState_window_miniaturize,
    eventState_window_zoom,
    eventState_keyboard_press,
    eventState_keyboard_release,
    eventState_selection_start,
    eventState_selection_end,
    eventState_focus_in,
    eventState_focus_out
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
    void (*listener)(event *eventClass, widget *target, void *extraArguments);
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