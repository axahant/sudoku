#ifndef PANEL_h
#define PANEL_h

#include "component.h"
#include "grid_layout.h"
#include "colors.h"

class Panel: public Component {
  private:
    int color;
    GridLayout layout;
  public:
    Panel();
    Panel(int _row, int _col, int _color = WHITE);
    void setRow(int _row);
    void setCol(int _col);
    void setColor(int _color);
    Rectangle getBounds();
    void setBounds(Rectangle rectangle);
    void paint(Elegoo_TFTLCD* tft);
};

#endif