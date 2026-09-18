#ifndef mainWindowHpp
#define mainWindowHpp
#if !(defined __WIN32 && defined __WIN64)
#ifdef WaylandEnabled
#define graphicDisplay struct wl_display
#else
#define graphicDisplay Display
#endif
#endif
#include "commonWidgetInterface.hpp"

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
    } icon;
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
    Screen *screen;
    mainWindow(int argc, char *argv[], char *envp[], const char *title);
    #endif
    ~mainWindow();
    int show(unsigned int microseconds) override;
    int hide(unsigned int microseconds) override;
};
#endif
