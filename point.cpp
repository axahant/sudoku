#include "point.h"
#include "grid_layout.h"

Point::Point() {
  x = 0;
  y = 0;
}

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

void Point::setX(int _x) {
  x = _x;
}

void Point::setY(int _y) {
  y = _y;
}

void Point::print() {
  Serial.print("(");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(")");
}

void Point::println() {
  print();
  Serial.println();
}
