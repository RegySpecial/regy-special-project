#ifndef mainWindowHpp
#define mainWindowHpp
#include "commonWidgetInterface.hpp"
#include "../c/manageArguments.h"
#include "../../lib/c++/bitManipulation.hpp"
#include "../c/generalPurposeMaskBits.h"
#if !(defined __WIN32 && defined __WIN64)
typedef
#ifdef WaylandEnabled
struct wl_display
#else
Display
#endif
graphicDisplay;
#endif

class mainScreenButton;

class mainWindow : public commonWidgetInterface
{
  public:
    struct
    {
      unsigned long color : 24 = 0,
                    *pixelMap;
      unsigned int x = 0,
                   y = 0;
      int width =  0,
          height = 0;
    }
    icon;
    #if defined __WIN32 || defined __WIN64
    HINSTANCE hInst,
              hInstPrev;
    char *cmdline;
    int cmdshow;
    mainWindow(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow, const char *title);
    #else
    int argc;
    char**argv,
        **envp;
    graphicDisplay *display;
    #ifndef WaylandEnabled
    Screen *screen;
    #endif
    gameContextStructure gameContext;
    struct
    {
      dynamicArray<windowType> subWindowIdentifiers;
      dynamicArray<void (*)(XClientMessageEvent *event, void *extraArgs)> clientMessageEventListeners;
      dynamicArray<void (*)(XResizeRequestEvent *event, void *extraArgs)> resizeEventListeners;
      dynamicArray<void (*)(XButtonReleasedEvent *event, void *extraArgs)> buttonUpEventListeners;
      dynamicArray<void (*)(XButtonPressedEvent *event, void *extraArgs)> buttonDownEventListeners;
      dynamicArray<void (*)(XKeyReleasedEvent *event, void *extraArgs)> keyUpEventListeners;
      dynamicArray<void (*)(XKeyPressedEvent *event, void *extraArgs)> keyDownEventListeners;
      dynamicArray<void (*)(XExposeEvent *event, void *extraArgs)> exposeEventListeners;
      dynamicArray<void (*)(XEnterWindowEvent *event, void *extraArgs)> pointerInEventListeners;
      dynamicArray<void (*)(XLeaveWindowEvent *event, void *extraArgs)> pointerOutEventListeners;
      dynamicArray<void (*)(XMotionEvent *event, void *extraArgs)> pointerMoveEventListeners;
      dynamicArray<void (*)(XFocusInEvent *event, void *extraArgs)> focusInEventListeners;
      dynamicArray<void (*)(XFocusOutEvent *event, void *extraArgs)> focusOutEventListeners;
      dynamicArray<void (*)(XAnyEvent *event, void *extraArgs)> anyEventListeners;
    }
    requestStruct;
    
    mainWindow(int argc, char *argv[], char *envp[], const char *title);
    #endif
    ~mainWindow();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
    void eventLoop(unsigned int microseconds);
};
#endif