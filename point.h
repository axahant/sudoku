#ifndef POINT_h
#define POINT_h

#include <Elegoo_TFTLCD.h>

class Point {
  private:

    int x;
    int y;

  public:

    Point() {
      x = 0;
      y = 0;
    }

    Point(int _x, int _y) {
      x = _x;
      y = _y;
    }

    int getX() {
      return x;
    }

    int getY() {
      return y;
    }

    void setX(int _x) {
      x = _x;
    }

    void setY(int _y) {
      y = _y;
    }

    void copy(Point _point) {
      x = _point.getX();
      y = _point.getY();
    }

    void print() {
      Serial.print("(");
      Serial.print(x);
      Serial.print(",");
      Serial.print(y);
      Serial.print(")");
    }

    void println() {
      print();
      Serial.println();
    }

};

#endif
