#ifndef eventsH
#define eventsH
typedef enum{
#if defined __WIN32||defined __WIN64
#else
  eventIdentifier_keyDown=2,
#endif
  eventIdentifier_keyUp,
  eventIdentifier_mouseDown,
  eventIdentifier_mouseUp,
  eventIdentifier_move,
  eventIdentifier_enter,
  eventIdentifier_leave,
  eventIdentifier_focus, 
  eventIdentifier_blur,
  eventIdentifier_keyMap,
  eventIdentifier_view,
  eventIdentifier_graphicShow,
  eventIdentifier_unview,
  eventIdentifier_visible,
  eventIdentifier_create,
  eventIdentifier_destroy,
  eventIdentifier_hide,
  eventIdentifier_show,
  eventIdentifier_askShow,
  eventIdentifier_reparent,
  eventIdentifier_config,
  eventIdentifier_askConfig,
  eventIdentifier_gravity,
  eventIdentifier_resize,
  eventIdentifier_circulate,
  eventIdentifier_askCirculate,
  eventIdentifier_property,
  eventIdentifier_unselect,
  eventIdentifier_askSelect, 
  eventIdentifier_select,
  eventIdentifier_colorMap,
  eventIdentifier_message,
  eventIdentifier_showing,
  eventIdentifier_event,
  eventIdentifier_lastEvent
}eventIdentifier;
#endif