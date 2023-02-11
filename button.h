#ifndef BUTTON_h
#define BUTTON_h

#include "point.h"
#include "component.h"

class Button: public Component {
  private:
    Point topLeft;
    Point bottomRight;

  public:
    Button();
    Button(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif