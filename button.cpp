#include "point.h"
#include "label.h"
#include "colors.h"
#include "button.h"

#include <Elegoo_TFTLCD.h>

Button::Button() {
  addChild(&label);
} 

Button::Button(String _label, int size) {
  label.setText(_label);
  label.setSize(size);
  addChild(&label);
}

Button::Button(String _label, int size, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
  label.setText(_label);
  label.setSize(size);
  addChild(&label);
  bounds.setTopLeft(topLeftX, topLeftY);
  bounds.setBottomRight(bottomRightX, bottomRightY);
}

Rectangle Button::getBounds() {
  return bounds; 
}

void Button::setBounds(Rectangle rectangle) {
  bounds.setTopLeft(rectangle.getTopLeft().getX(), rectangle.getTopLeft().getY());
  bounds.setBottomRight(rectangle.getBottomRight().getX(), rectangle.getBottomRight().getY());
  rectangle.println();
  label.setBounds(rectangle);
}

void Button::paint(Elegoo_TFTLCD* tft) {
  tft->fillRoundRect(bounds.getTopLeft().getX(), bounds.getTopLeft().getY(), bounds.getWidth(), bounds.getHeight(), 5, CYAN);
  tft->drawRoundRect(bounds.getTopLeft().getX(), bounds.getTopLeft().getY(), bounds.getWidth(), bounds.getHeight(), 5, WHITE);
  paintChildren(tft);
}
