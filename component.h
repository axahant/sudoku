#ifndef COMPONENT_h
#define COMPONENT_h

#include <Elegoo_TFTLCD.h>

#include "rectangle.h"

class Component {
  private:

    int childCount;
    Component *children[16];

  public:

    Component() {
      childCount = 0;
    }

    void addChild(Component *child) {
      children[childCount] = child;
      childCount = childCount + 1;
    }

    int getChildCount() {
      return childCount;
    }

    Component** getChildren() {
      return children;
    }

    void paintChildren(Elegoo_TFTLCD* tft) {
      for(int n = 0; n < childCount; n++) {
        children[n]->paint(tft);  
      }
    }

    virtual Rectangle getBounds();
    virtual void setBounds(Rectangle rectangle);
    virtual void paint(Elegoo_TFTLCD* tft);

};

#endif
