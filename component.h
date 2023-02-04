#ifndef COMPONENT_h
#define COMPONENT_h
#include <Elegoo_TFTLCD.h>

class Component {
  public:
    virtual void paint(Elegoo_TFTLCD* tft);
};

#endif