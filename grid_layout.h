#ifndef GLAYOUT_h
#define GLAYOUT_h

#include "layout.h"
#include "component.h"
#include "rectangle.h"

class GridLayout: public Layout {
  private:
    int row;
    int col;
    int rowPadding;
    int colPadding;
    Rectangle rectangle;
  public:
    GridLayout(Rectangle rectangle, int _row, int _col, int _rowPadding = 0, int _colPadding = 0);
    void layout(Component *_component);
};

#endif
