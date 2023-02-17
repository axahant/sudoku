#include "HardwareSerial.h"
#include "component.h"
#include "rectangle.h"
#include "grid_layout.h"

GridLayout::GridLayout() {
  row = 1;
  col = 1;
  rowPadding = 0;
  colPadding = 0;
}

GridLayout::GridLayout(Rectangle _rectangle, int _row, int _col, int _rowPadding, int _colPadding) {
  row = _row;
  col = _col;
  rowPadding = _rowPadding;
  colPadding = _colPadding;
  bounds.copy(_rectangle);
}

Rectangle GridLayout::getBounds() {
 return bounds;
}

void GridLayout::setBounds(Rectangle _rectangle) {
  bounds.copy(_rectangle);
}

void GridLayout::setRow(int _row) {
  row = _row;
}

void GridLayout::setCol(int _col) {
  col = _col;
}

void GridLayout::layout(Component *_component) {
  int childCount = _component->getChildCount();
  Component **children = _component->getChildren();

  int width = bounds.getWidth();
  int height = bounds.getHeight();
  int cellWidth = width / col;
  int cellHeight = height / row;

  Serial.print("Child count: ");
  Serial.println(childCount);
  bounds.println();
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

        _bounds.println();

        children[componentIndex]->setBounds(_bounds);
      }
    }
  }
}
