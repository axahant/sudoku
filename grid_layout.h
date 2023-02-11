#ifndef GLAYOUT_h
#define GLAYOUT_h

#include "layout.h"
#include "component.h"
#include "rectangle.h"

class GridLayout: public Layout {
  private:
    int row;
    int col;
    Rectangle rectangle;
  public:
    GridLayout(Rectangle rectangle, int _row, int _col);
    void layout(Component *_component);
};

#endif
