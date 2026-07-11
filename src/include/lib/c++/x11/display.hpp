#ifndef displayHpp
#define displayHpp
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<assert.h>
#include<errno.h>
#include<unistd.h>
#include"../../lib/c++/DSA/dataStructures/dynamicArrays.hpp"
namespace x11{
  class display{
    public:
      Display*nativeHandle;
      int screenNumber,
          depth;
      Window rootWindow;
      Screen*screen;
      XVisualInfo visualInfo;
      char*displayName;
      int connectionNumber,
          vendorRelease;
      display(char*displayName);
      void unlock();
      void lock();
      ~display();
      int nextEvent(XEvent*event);
      void flush();
      int storeBuffer(const char*bytes,int nbytes,int buffer);
      int storeBytes(const char*bytes,int nbytes);
      int sync(bool discard);
  };
}
#endif