#ifndef LABEL_h
#define LABEL_h

#include "point.h"
#include "component.h"

class Label: public Component {
  private:
    String text;
    int size; 
    Rectangle bounds;
  public:
    Label();
    Label(String _text, int _size = 1);
    void setText(String _text);
    void setSize(int _size);
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif