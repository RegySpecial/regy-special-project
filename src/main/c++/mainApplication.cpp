#include "../../include/main/c++/mainApplication.hpp"

#if defined __WIN32 || defined __WIN64
mainApplication::mainApplication(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow)
{
  this->hInst = hInst;
  this->hInstPrev = hInstPrev;
  this->cmdline = cmdline;
  this->cmdshow = cmdshow;
}
#else
mainApplication::mainApplication(int argc, char **argv, char **envp)
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

  this->screen = XDefaultScreenOfDisplay(this->display);
}
#endif

mainApplication::~mainApplication()
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

void mainApplication::eventLoop(unsigned int microseconds)
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

class mainApplication
{
  public:
    #if defined __WIN32 || defined __WIN64
    HINSTANCE hInst,
              hInstPrev;
    char *cmdline;
    int cmdshow;
    mainApplication(HINSTANCE hInst, HINSTANCE hInstPrev, char *cmdline, int cmdshow);
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
    mainApplication(int argc, char **argv, char **envp);
    ~mainApplication();
    void eventLoop(unsigned int microseconds);
    #endif
};