#ifndef RECTANGLE_h
#define RECTANGLE_h

#include "point.h"
#include "component.h"

class Rectangle {
  private:
    Point topLeft;
    Point bottomRight;

  public:
    Rectangle();
    Rectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
    Point getTopLeft();
    Point getBottomRight();
    void setTopLeft(int topLeftX, int topLeftY);
    void setBottomRight(int bottomRightX, int bottomRightY);
};

#endif