#include "point.h"
#include "colors.h"
#include "button.h"

#include <Elegoo_TFTLCD.h>

Button::Button(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
  Point _topLeft(topLeftX, topLeftY);
  Point _bottomRight(bottomRightX, bottomRightY);
  topLeft = &_topLeft;
  bottomRight = &_bottomRight;
}

void Button::paint(Elegoo_TFTLCD* tft) {
  tft->drawRect(topLeft->getX(), topLeft->getY(), bottomRight->getX(), bottomRight->getY(), RED);
}
