#ifndef PANEL_h
#define PANEL_h

#include "colors.h"
#include "component.h"
#include "grid_layout.h"

class Panel: public Component {
  private:

    int color;
    GridLayout layout;

  public:

    Panel() {
      color = -1;
    } 

    Panel(int _row, int _col, int _color = WHITE) {
      layout.setRow(_row);
      layout.setCol(_col);
      color = _color;
    } 

    void setRow(int _row) {
      layout.setRow(_row);
    }

    void setCol(int _col) {
      layout.setCol(_col);
    }

    void setColor(int _color) {
      color = _color;
    }

    virtual Rectangle getBounds() {
      return layout.getBounds();
    }

    virtual void setBounds(Rectangle rectangle) {
      layout.setBounds(rectangle);
      layout.layout(this);
    }

    virtual void paint(Elegoo_TFTLCD* tft) {
      if (color >= 0) {
        tft->fillRect(layout.getBounds().getTopLeft().getX(), layout.getBounds().getTopLeft().getY(), layout.getBounds().getWidth(), layout.getBounds().getHeight(), color);
      }
      paintChildren(tft);
    }

};

#endif
