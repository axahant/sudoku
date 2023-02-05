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

void Button::paint(Elegoo_TFTLCD* tft) {
  Serial.println("Button paint called");
  tft->fillRoundRect(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY(), 5, CYAN);
  tft->drawRoundRect(topLeft.getX(), topLeft.getY(), bottomRight.getX(), bottomRight.getY(), 5, WHITE);
  tft->drawRoundRect(topLeft.getX() + 1, topLeft.getY() + 1, bottomRight.getX() - 2, bottomRight.getY() - 2, 5, WHITE);
  paintChildren(tft);
}
