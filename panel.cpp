#include "panel.h"
#include "colors.h"

#include <Elegoo_TFTLCD.h>

Panel::Panel() {
  color = -1;
} 

Panel::Panel(int _row, int _col, int _color) {
  layout.setRow(_row);
  layout.setCol(_col);
  color = _color;
} 

void Panel::setRow(int _row) {
  layout.setRow(_row);
}

void Panel::setCol(int _col) {
  layout.setCol(_col);
}

void Panel::setColor(int _color) {
  color = _color;
}

Rectangle Panel::getBounds() {
  return layout.getBounds();
}

void Panel::setBounds(Rectangle rectangle) {
  layout.setBounds(rectangle);
  layout.layout(this);
}

void Panel::paint(Elegoo_TFTLCD* tft) {
  if (color >= 0) {
    tft->fillRect(layout.getBounds().getTopLeft().getX(), layout.getBounds().getTopLeft().getY(), layout.getBounds().getWidth(), layout.getBounds().getHeight(), color);
  }
  paintChildren(tft);
}
