#ifndef POINT_h
#define POINT_h

#include <Elegoo_TFTLCD.h>

class Point {
  private:
    int x;
    int y;

  public:
    Point(int _x, int _y);
    int getX();
    int getY();
};

#endif