#ifndef BUTTON_h
#define BUTTON_h

#include "point.h"
#include "label.h"
#include "component.h"

class Button: public Component {
  private:

    Rectangle bounds;
    Label label;

  public:

    Button() {
      addChild(&label);
    } 

    Button(String _label, int size = 1) {
      label.setText(_label);
      label.setSize(size);
      addChild(&label);
    }

    Button(String _label, int size, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
      label.setText(_label);
      label.setSize(size);
      addChild(&label);
      bounds.setTopLeft(topLeftX, topLeftY);
      bounds.setBottomRight(bottomRightX, bottomRightY);
    }

    virtual Rectangle getBounds() {
      return bounds; 
    }

    virtual void setBounds(Rectangle rectangle) {
      bounds.setTopLeft(rectangle.getTopLeft().getX(), rectangle.getTopLeft().getY());
      bounds.setBottomRight(rectangle.getBottomRight().getX(), rectangle.getBottomRight().getY());
      rectangle.println();
      label.setBounds(rectangle);
    }

    virtual void paint(Elegoo_TFTLCD* tft) {
      tft->fillRoundRect(bounds.getTopLeft().getX(), bounds.getTopLeft().getY(), bounds.getWidth(), bounds.getHeight(), 5, CYAN);
      tft->drawRoundRect(bounds.getTopLeft().getX(), bounds.getTopLeft().getY(), bounds.getWidth(), bounds.getHeight(), 5, WHITE);
      paintChildren(tft);
    }

};

#endif
