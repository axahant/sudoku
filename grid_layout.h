#ifndef GLAYOUT_h
#define GLAYOUT_h

#include "layout.h"
#include "component.h"
#include "rectangle.h"

class GridLayout: public Layout {
  private:
    int row;
    int col;
    int rowPadding;
    int colPadding;
    Rectangle bounds;
  public:
    GridLayout() {
      row = 1;
      col = 1;
      rowPadding = 0;
      colPadding = 0;
    }

    GridLayout(Rectangle _rectangle, int _row = 1, int _col = 1, int _rowPadding = 0, int _colPadding = 0) {
      row = _row;
      col = _col;
      rowPadding = _rowPadding;
      colPadding = _colPadding;
      bounds.copy(_rectangle);
    }

    Rectangle getBounds() {
      return bounds;
    }

    void setBounds(Rectangle _rectangle) {
      bounds.copy(_rectangle);
    }
    
    void setRow(int _row) {
      row = _row;
    }

    void setCol(int _col) {
      col = _col;
    }

    virtual void layout(Component *_component) {
      int childCount = _component->getChildCount();
      Component **children = _component->getChildren();

      int width = bounds.getWidth();
      int height = bounds.getHeight();
      int cellWidth = width / col;
      int cellHeight = height / row;

      for (int i=0; i < row; i++) {
        for (int j=0; j < col; j++) {
          int componentIndex = (i * col) + j;

          if (componentIndex < childCount) {
            int topLeftX = bounds.getTopLeft().getX() + (j * cellWidth);
            int topLeftY = bounds.getTopLeft().getY() + (i * cellHeight);
            int bottomRightX = topLeftX + cellWidth; 
            int bottomRightY = topLeftY + cellHeight;
            topLeftX = topLeftX + colPadding;
            topLeftY = topLeftY + rowPadding;
            bottomRightX = bottomRightX - colPadding;
            bottomRightY = bottomRightY - rowPadding;

            Rectangle _bounds(topLeftX, topLeftY, bottomRightX, bottomRightY);

            children[componentIndex]->setBounds(_bounds);
          }
        }
      }
    }
};

#endif
