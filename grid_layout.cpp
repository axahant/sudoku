#include "component.h"
#include "rectangle.h"
#include "grid_layout.h"

GridLayout::GridLayout(Rectangle _rectangle, int _row, int _col, int _rowPadding, int _colPadding) {
  row = _row;
  col = _col;
  rowPadding = _rowPadding;
  colPadding = _colPadding;
  rectangle = _rectangle;
}

void GridLayout::layout(Component *_component) {
  int childCount = _component->getChildCount();
  Component **children = _component->getChildren();

  int width = rectangle.getBottomRight().getX() - rectangle.getTopLeft().getX();
  int height = rectangle.getBottomRight().getY() - rectangle.getTopLeft().getY();
  int cellWidth = width / col;
  int cellHeight = height / row;

  for (int i=0; i < row; i++) {
    for (int j=0; j < col; j++) {
      int componentIndex = (i * col) + j;

      if (componentIndex < childCount) {
        int topLeftX = rectangle.getTopLeft().getX() + (j * cellWidth);
        int topLeftY = rectangle.getTopLeft().getY() + (i * cellHeight);
        int bottomRightX = topLeftX + cellWidth; 
        int bottomRightY = topLeftY + cellHeight;
        topLeftX = topLeftX + colPadding;
        topLeftY = topLeftY + rowPadding;
        bottomRightX = bottomRightX - colPadding;
        bottomRightY = bottomRightY - rowPadding;

        Rectangle bounds(topLeftX, topLeftY, bottomRightX, bottomRightY);

        children[componentIndex]->setBounds(bounds);
      }
    }
  }
}
