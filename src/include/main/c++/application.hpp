#ifndef applicationHpp
#define applicationHpp

#include "../c/events.h"

class application
{
  public:
    #if defined __WIN32 || defined __WIN64
    HINSTANCE hInst,
              hInstPrev;
    char *cmdline;
    int cmdshow;
    application(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow);
    #else
    int argc;
    char
      **argv,
      **envp;
    displayConnection *display;
    gameContextStructure gameContextContainer;
    dynamicArray<event> events;
    #ifndef waylandEnabled
    Screen *screen;
    #endif
    application(int argc, char **argv, char **envp);
    ~application();
    void eventLoop(unsigned int microseconds);
    #endif
};
#endif