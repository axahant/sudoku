#ifndef WELCOME_SCREEN_h
#define WECOME_SCREEN_h

#include "panel.h"

#include <Elegoo_TFTLCD.h>

class WelcomeScreen: public Panel {
  private:
    Panel topPanel;
    Panel bottomPanel; 
    Label welcomeLabel;
    Label sudokuLabel;
    Label emptyLabel;
    Label myNameLabel;
    Label myYearLabel;
  public:
    WelcomeScreen(Elegoo_TFTLCD *tft);
};

#endif