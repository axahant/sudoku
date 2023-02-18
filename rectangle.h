#ifndef RECTANGLE_h
#define RECTANGLE_h

#include "point.h"

class Rectangle {
  private:

    Point topLeft;
    Point bottomRight;

  public:

    Rectangle() {
    }

    Rectangle(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
      topLeft.setX(topLeftX);
      topLeft.setY(topLeftY);
      bottomRight.setX(bottomRightX); 
      bottomRight.setY(bottomRightY);
    }
    
    Point getTopLeft() {
      return topLeft;
    }

    Point getBottomRight() {
      return bottomRight; 
    }

    void setTopLeft(int topLeftX, int topLeftY) {
      topLeft.setX(topLeftX);
      topLeft.setY(topLeftY);
    }

    void setBottomRight(int bottomRightX, int bottomRightY) {
      bottomRight.setX(bottomRightX);
      bottomRight.setY(bottomRightY);
    }

    int getWidth() {
      return bottomRight.getX() - topLeft.getX();
    }

    int getHeight() {
      return bottomRight.getY() - topLeft.getY(); 
    }

    void copy(Rectangle _rectangle) {
      topLeft.copy(_rectangle.getTopLeft());
      bottomRight.copy(_rectangle.getBottomRight());
    }

    void print() {
      topLeft.print();
      Serial.print(" - ");
      bottomRight.print();
    }

    void println() {
      print();
      Serial.println();
    }

};

#endif
