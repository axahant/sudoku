#ifndef BUTTON_h
#define BUTTON_h

#include "Point.h"

class Button {
  private:
    Point topLeft;
    Point bottomRight;

  public:
    Button(Point _topLeft, Point _bottomRight);
};

#endif