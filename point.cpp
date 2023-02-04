#include "point.h"

Point::Point(int _x, int _y) {
  x = _x;
  y = _y;
  Serial.println(x);
  Serial.println(y);
}

int Point::getX() {
  return x;
}

int Point::getY() {
  return y;
}