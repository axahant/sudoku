#ifndef NOPLAYOUT_h
#define NOPLAYOUT_h

#include "layout.h"
#include "component.h"

class NoOpLayout: public Layout {
  public:
  NoOpLayout();
  void layout(Component *_component);
};

#endif
