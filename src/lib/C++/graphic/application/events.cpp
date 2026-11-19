
#include "../../../../include/lib/c++/graphic/application/events.hpp"

event::event(widget *target, eventState state)
{
  if (eventState_mouse_press <= state && state <= eventState_focus_out)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

mouseEvent::mouseEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_mouse_press <= state && state <= eventState_mouse_release)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

pointerEvent::pointerEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_mouse_press <= state && state <= eventState_mouse_release)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

widgetEvent::widgetEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_widget_create <= state && state <= eventState_widget_hide)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

keyboardEvent::keyboardEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_keyboard_press <= state && state <= eventState_keyboard_release)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

selectionEvent::selectionEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_selection_start <= state && state <= eventState_selection_end)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}

focusEvent::focusEvent(widget *target, eventState state)
: event(target, state)
{
  if (eventState_focus_in <= state && state <= eventState_focus_out)
  {
    this->target = target;
    this->state = state;
  }
  else
    return;
}