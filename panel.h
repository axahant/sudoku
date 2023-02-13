#ifndef PANEL_h
#define PANEL_h

#include "component.h"

class Panel: public Component {
  private:
  public:
    Panel();
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif