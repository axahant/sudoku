#ifndef OPTIONS_SCREEN_h
#define OPTIONS_SCREEN_h

#include "label.h"
#include "panel.h"
#include "colors.h"

#include <Elegoo_TFTLCD.h>

class OptionsScreen: public Panel {
  private:

    Panel topPanel;
    Panel bottomPanel; 
    Label welcomeLabel;
    Label sudokuLabel;
    Label emptyLabel;
    Label myNameLabel;
    Label myYearLabel;

  public:

    OptionsScreen() {
      setRow(2);
      setColor(BLACK);
      addChild(&topPanel);

      topPanel.setRow(2);

      bottomPanel.setRow(3);
      bottomPanel.setCol(1);
      addChild(&bottomPanel);

      welcomeLabel.setText("Options");
      welcomeLabel.setSize(5);
      welcomeLabel.setColor(YELLOW);
      topPanel.addChild(&welcomeLabel);

      sudokuLabel.setText("Arduino Sudoku");
      sudokuLabel.setSize(3);
      topPanel.addChild(&sudokuLabel);

      bottomPanel.addChild(&emptyLabel);

      myNameLabel.setText("Axahant Dubey");
      myNameLabel.setSize(3);
      bottomPanel.addChild(&myNameLabel);

      myYearLabel.setText("Year 7 Hawks");
      myYearLabel.setSize(2);
      myYearLabel.setColor(GREEN);
      bottomPanel.addChild(&myYearLabel);
    }

    void init(Elegoo_TFTLCD *tft) {
      Rectangle tftRectangle(0, 0, tft->width() - 1, tft->height() - 1);
      setBounds(tftRectangle);
    }

};

#endif
