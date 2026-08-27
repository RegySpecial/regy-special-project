public class form:commonWidgetInterface{
  public var id:NSPanel!
  public var root:mainWindow
  init(_ root:mainWindow){
    self.root=root;
    self.x=self.root.width*20/100,//20% of screen.width
    self.y=self.root.height*20/100,//20% of screen.width
    self.width=self.root.width-2*self.root.width*20/100,//screen.width-2*form.x
    self.height=self.root.height-2*self.root.height*20/100,//screen.width-2*form.x
    self.border = borderStruct(2,0)
    self.background.color = backgroundStruct()
  }
}
#include "../../include/main/c++/form.hpp"

form::form(mainWindow*root){
  self.root=root;
  self.x=self.root.width*20/100,//20% of screen.width
  self.y=self.root.height*20/100,//20% of screen.width
  self.width=self.root.width-2*self.root.width*20/100,//screen.width-2*form.x
  self.height=self.root.height-2*self.root.height*20/100,//screen.width-2*form.x
  self.border={
    2,//width
    0//color
  };
  XSetWindowAttributes formAttributes{
    .background_pixel=(self.background.color=0xffffff),
    .border_pixel=self.border.color,
    .event_mask=(self.eventMask=ExposureMask)
  };
  self.id=XCreateWindow(
    self.root.display,
    self.root.id,
    self.x,//20% of screen.width
    self.y,//20% of screen.width
    self.width,//screen.width-2*form.x
    self.height,//screen.width-2*form.x
    self.border.width,
    self.root.visualInfo.depth,//depth
    self.root.visualInfo.c_class,//window class
    self.root.visualInfo.visual,//visual
    (self.attributeMask=CWBorderPixel|CWBackPixel|CWEventMask),
    &formAttributes
  );
}
form::~form(){
  XDestroySubwindows(self.root.display,self.id);
}