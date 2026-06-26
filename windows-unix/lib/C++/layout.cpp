#include<X11/Xlib.h>
#include<X11/Xutil.h>
void stackLayout(Window*windows,unsigned int gridX,unsigned int gridY){

}
void queueLayout(Window*windows,unsigned int gridX,unsigned int gridY){

}
void gridLayout(
  Display*display,
  Window**windows,
  unsigned int gridX,
  unsigned int gridY,
  unsigned int gridWidth,
  unsigned int gridHeight,
  unsigned int rows,
  unsigned int columns,
  unsigned int xGap,
  unsigned int yGap
)
{
  for(unsigned int y=0;y<rows;y++){
    for(unsigned int x=0;x<columns;x++){
      XMoveResizeWindow(
        display,
        windows[y][x],
        gridX+xGap+gridWidth/columns*x,
        gridY+yGap+gridHeight/rows*y,
        gridWidth/columns-2*xGap,
        gridHeight/rows-2*yGap
      );
      XMapRaised(display,windows[y][x]);
    }
  }
}