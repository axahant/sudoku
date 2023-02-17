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

int Rectangle::getWidth() {
  return bottomRight.getX() - topLeft.getX();
}

int Rectangle::getHeight() {
  return bottomRight.getY() - topLeft.getY(); 
}

void Rectangle::copy(Rectangle _rectangle) {
  topLeft.setX(_rectangle.getTopLeft().getX());
  topLeft.setY(_rectangle.getTopLeft().getY());
  bottomRight.setX(_rectangle.getBottomRight().getX());
  bottomRight.setY(_rectangle.getBottomRight().getY());
}

void Rectangle::print() {
  topLeft.print();
  Serial.print(" - ");
  bottomRight.print();
}

void Rectangle::println() {
  print();
  Serial.println();
}
