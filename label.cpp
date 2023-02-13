#include "point.h"
#include "colors.h"
#include "label.h"

#include <Elegoo_TFTLCD.h>

Label::Label() {
  text = "";
  size = 1;
}

Label::Label(String _text, int _size) {
  text = _text;
  size = _size;
}

void Label::setText(String _text) {
  text = _text;
}

void Label::setSize(int _size) {
  size = _size;
}

void Label::setBounds(Rectangle rectangle) {
  bounds.setTopLeft(rectangle.getTopLeft().getX(), rectangle.getTopLeft().getY());
  bounds.setBottomRight(rectangle.getBottomRight().getX(), rectangle.getBottomRight().getY());
}

void Label::paint(Elegoo_TFTLCD* tft) {
  int charPixelWidth = 6 * size;
  int charPixelHeight = 7 * size;

  int tw = charPixelWidth * text.length();
  int x = bounds.getTopLeft().getX() + (bounds.getWidth() - tw)/2;
  int th = charPixelHeight;
  int y = bounds.getTopLeft().getY() + (bounds.getHeight() - th)/2;
  tft->setCursor(x,y); 
  tft->setTextColor(WHITE);
  tft->setTextSize(size);
  tft->print(text);
  paintChildren(tft);
}
