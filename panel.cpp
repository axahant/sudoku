#include "panel.h"

#include <Elegoo_TFTLCD.h>

Panel::Panel() {
} 

void Panel::setBounds(Rectangle rectangle) {
}

void Panel::paint(Elegoo_TFTLCD* tft) {
  paintChildren(tft);
}
