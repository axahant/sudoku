#ifndef RECTANGLE_h
#define RECTANGLE_h

#include "point.h"

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
    int getWidth();
    int getHeight();
    void print();
    void println();
};

#endif