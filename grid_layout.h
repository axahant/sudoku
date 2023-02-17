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
    Rectangle bounds;
  public:
    GridLayout();
    GridLayout(Rectangle _rectangle, int _row = 1, int _col = 1, int _rowPadding = 0, int _colPadding = 0);
    Rectangle getBounds();
    void setBounds(Rectangle _rectangle);
    void setRow(int _row);
    void setCol(int _col);
    void layout(Component *_component);
};

#endif
