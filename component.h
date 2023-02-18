#ifndef COMPONENT_h
#define COMPONENT_h

#include <Elegoo_TFTLCD.h>

#include "rectangle.h"

class Component {
  private:

    int childCount;
    Component *children[16];

  protected:
    bool dirty;
    virtual void paintComponent(Elegoo_TFTLCD* tft);

  public:

    Component() {
      dirty = true;
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
        if (children[n]->getDirty()) {
          children[n]->paint(tft);
        }
      }
    }

    bool getDirty() {
      return dirty;
    }

    void setDirty() {
      dirty = true;
      for (int n = 0; n < childCount; n++) {
        children[n]->setDirty();
      }
    }

    void paint(Elegoo_TFTLCD* tft) {
      if (dirty) {
        dirty = false;
        paintComponent(tft);
      }
      paintChildren(tft);
    }

    virtual Rectangle getBounds();
    virtual void setBounds(Rectangle rectangle);

};

#endif
