#include "point.h"
#include "rectangle.h"

Rectangle::Rectangle() {
}

Rectangle::Rectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
  topLeft.setX(topLeftX);
  topLeft.setY(topLeftY);
  bottomRight.setX(bottomRightX);
  bottomRight.setY(bottomRightY);
}

Point Rectangle::getTopLeft() {
  return topLeft;
}

Point Rectangle::getBottomRight() {
  return bottomRight; 
}

void Rectangle::setTopLeft(int topLeftX, int topLeftY) {
  topLeft.setX(topLeftX);
  topLeft.setY(topLeftY);
}

void Rectangle::setBottomRight(int bottomRightX, int bottomRightY) {
  bottomRight.setX(bottomRightX);
  bottomRight.setY(bottomRightY);
}