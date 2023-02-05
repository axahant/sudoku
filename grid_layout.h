#ifndef GLAYOUT_h
#define GLAYOUT_h

#include "layout.h"
#include "component.h"

class GridLayout: public Layout {
  private:
  int row;
  int col;
  public:
  GridLayout(int _row, int _col);
  void layout(Component *_component);
};

#endif
