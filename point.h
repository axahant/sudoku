#ifndef POINT_h
#define POINT_h

#include <Elegoo_TFTLCD.h>

class Point {
  private:
    int x;
    int y;

  public:
    Point();
    Point(int _x, int _y);
    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);
    void print();
    void println();
};

#endif