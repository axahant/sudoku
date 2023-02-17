#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "tft.h"
#include "point.h"
#include "button.h"
#include "colors.h"
#include "component.h"
#include "grid_layout.h"
#include "label.h"
#include "panel.h"
#include "welcome_screen.h"

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);
  tft.setRotation(3);

  WelcomeScreen screen(&tft);

  screen.paint(&tft);
}

void loop() {
}