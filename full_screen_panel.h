#ifndef FULL_SCREEN_PANEL_h
#define FULL_SCREEN_PANEL_h

#include "panel.h"

#include <Elegoo_TFTLCD.h>

class FullScreenPanel: public Panel {
  public:

    FullScreenPanel() {
    }

    void init(Elegoo_TFTLCD *tft) {
      Rectangle tftRectangle(0, 0, tft->width(), tft->height());
      setBounds(tftRectangle);
    }

};

#endif
