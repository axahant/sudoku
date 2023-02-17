#ifndef LABEL_h
#define LABEL_h

#include "point.h"
#include "component.h"
#include "colors.h"

class Label: public Component {
  private:
    String text;
    int size; 
    Rectangle bounds;
    int color; 
  public:
    Label();
    Label(String _text, int _size = 1, int _color = WHITE);
    void setText(String _text);
    void setSize(int _size);
    void setColor(int _color);
    Rectangle getBounds();
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif