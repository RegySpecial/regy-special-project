#ifndef pixmapHpp
#define pixmapHpp
#include "cursor.hpp"
namespace x11{
  class pixmap{
    public:
      Pixmap id;
      x11::drawable*drawable;
      char*data;
      unsigned int x=0,y=0,width,height;
      pixmap(x11::drawable*drawable){
        this->drawable=drawable;
        this->id=XCreatePixmap(
          this->drawable->display->nativeHandle,
          this->drawable->id,
          this->width,
          this->height,
          this->drawable->display->depth
        );
      }
      ~pixmap(){
        XFreePixmap(
          this->drawable->display->nativeHandle,
          this->drawable->id
        );
      }
  };
}
#endif