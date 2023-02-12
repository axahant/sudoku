#include "point.h"
#include "colors.h"
#include "button.h"

#include <Elegoo_TFTLCD.h>

Button::Button() {
}

Button::Button(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
  topLeft.setX(topLeftX);
  topLeft.setY(topLeftY);
  bottomRight.setX(bottomRightX);
  bottomRight.setY(bottomRightY);
}

void Button::setBounds(Rectangle rectangle) {
  topLeft.setX(rectangle.getTopLeft().getX());
  topLeft.setY(rectangle.getTopLeft().getY());
  bottomRight.setX(rectangle.getBottomRight().getX());
  bottomRight.setY(rectangle.getBottomRight().getY());
}

void Button::paint(Elegoo_TFTLCD* tft) {
  tft->fillRoundRect(topLeft.getX(), topLeft.getY(), bottomRight.getX() - topLeft.getX(), bottomRight.getY() - topLeft.getY(), 5, CYAN);
  tft->drawRoundRect(topLeft.getX(), topLeft.getY(), bottomRight.getX() - topLeft.getX(), bottomRight.getY() - topLeft.getY(), 5, WHITE);
  paintChildren(tft);
}
