#include "point.h"
#include "colors.h"
#include "label.h"

#include <Elegoo_TFTLCD.h>

Label::Label(String _text, int _size) {
  text = _text;
  size = _size;
}

void Label::setBounds(Rectangle rectangle) {
  rectangle.println();
  bounds = rectangle;
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
