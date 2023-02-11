#include "component.h"

Component::Component() {
  childCount = 0;
}

void Component::addChild(Component *child) {
  children[childCount] = child;
  childCount = childCount + 1;
}

void Component::paintChildren(Elegoo_TFTLCD* tft) {
  for(int n = 0; n < childCount; n++) {
    children[n]->paint(tft);  
  }
}

int Component::getChildCount() {
  return childCount;
}

Component** Component::getChildren() {
  return children;
}