#include "../../include/main/c++/application.hpp"

#if defined __WIN32 || defined __WIN64
application::application(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow)
{
  this->hInst = hInst;
  this->hInstPrev = hInstPrev;
  this->cmdline = cmdline;
  this->cmdshow = cmdshow;
}
#else
application::application(int argc, char **argv, char **envp)
{
  this->argc = argc;
  this->argv = argv;
  this->envp = envp;

  this->gameContextContainer = manageCommandLineArguments(this->argc, this->argv);

  this->display = 
  #ifdef WaylandEnabled
  wl_display_connect
  #else
  XOpenDisplay
  #endif
  (0);

  if (!this->display)
  {
    failureMessage
    (
      "Cannot establish a connection with the "
      #ifdef WaylandEnabled
      "Wayland"
      #else
      "X"
      #endif
      " Graphic Server"
    );
    abort();
  }

  this->screen = XDefaultScreenOfDisplay(this->display);

  if (!this->screen)
  {
    failureMessage("cannot get informations about the screen");
    abort();
  }
}
#endif

application::~application()
{
  #if defined __WIN32 || defined __WIN64
  #else
  #ifdef WaylandEnabled
  wl_display_disconnect
  #else
  XCloseDisplay
  #endif
  (this->display);
  #endif
}

void application::eventLoop(unsigned int microseconds)
{
  #if defined __WIN32 || defined __WIN64
  Sleep
  #else
  usleep
  #endif
  (microseconds);

  for (XEvent event; readBit<unsigned char>(this->gameContextContainer.generalPurposeMask, generalPurposeMaskBits_eventLoop);)
  {
    XNextEvent(this->display, &event);
  }
}

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
    gameContextStructure gameContextContainer;
    displayConnection *display;
    #ifndef waylandEnabled
    Screen *screen;
    #endif
    application(int argc, char **argv, char **envp);
    ~application();
    void eventLoop(unsigned int microseconds);
    #endif
};