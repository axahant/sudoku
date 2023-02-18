#ifndef LABEL_h
#define LABEL_h

#include "colors.h"
#include "component.h"

class Label: public Component {
  private:
  
    String text;
    int size; 
    Rectangle bounds;
    int color;

  protected:

    virtual void paintComponent(Elegoo_TFTLCD* tft) {
      int charPixelWidth = 6 * size;
      int charPixelHeight = 7 * size;

      int tw = charPixelWidth * text.length();
      int x = bounds.getTopLeft().getX() + (bounds.getWidth() - tw)/2;
      int th = charPixelHeight;
      int y = bounds.getTopLeft().getY() + (bounds.getHeight() - th)/2;
      tft->setCursor(x,y); 
      tft->setTextColor(color);
      tft->setTextSize(size);
      tft->print(text);
    }

  public:

    Label() {
      size = 1;
      color = WHITE;
    }

    Label(String _text, int _size = 1, int _color = WHITE) {
      text = _text;
      size = _size;
      color = _color;
    }

    void setText(String _text) {
      text = _text;
      setDirty();
    }

    void setSize(int _size) {
      size = _size;
      setDirty();
    }

    void setColor(int _color) {
      color = _color;
      setDirty();
    }

    virtual Rectangle getBounds() {
      return bounds; 
    }

    virtual void setBounds(Rectangle rectangle) {
      bounds.setTopLeft(rectangle.getTopLeft().getX(), rectangle.getTopLeft().getY());
      bounds.setBottomRight(rectangle.getBottomRight().getX(), rectangle.getBottomRight().getY());
      setDirty();
    }

};

#endif
