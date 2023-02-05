#ifndef COMPONENT_h
#define COMPONENT_h
#include <Elegoo_TFTLCD.h>

class Component {
  private:
    int childCount;
    Component *children[16];
  public:
    Component();
    virtual void paint(Elegoo_TFTLCD* tft);
    void paintChildren(Elegoo_TFTLCD* tft);
    void addChild(Component *child);
};

#endif