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
    Button();
    Button(String _label, int size = 1);
    Button(String _label, int size, int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
    Rectangle getBounds();
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif