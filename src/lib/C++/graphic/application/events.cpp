
#include "../../../../include/lib/c++/graphic/application/events.hpp"

event::event(widget *target, eventState state)
{
  this->target = target;
  this->state = state;
}

mouseEvent::mouseEvent(widget *target, eventState state) : event::event(target, state)
{
  if (eventState_mouse_press > state || state > eventState_mouse_release)
    return;
  
  event eventClass(target, state);
}

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