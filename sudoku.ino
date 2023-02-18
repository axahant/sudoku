#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "tft.h"
#include "panel.h"
#include "welcome_screen.h"
#include "options_screen.h"

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

WelcomeScreen wScreen;
OptionsScreen oScreen;
Panel *screen;

int i = 0;

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);
  tft.setRotation(3);

  wScreen.init(&tft);
  oScreen.init(&tft);

  screen = &wScreen;
}

void loop() {
  i++;

  if (i%5 == 0) {
    if (screen == &wScreen) {
      screen = &oScreen;
    } else {
      screen = &wScreen;
    }
    i = 0;
  }

  screen->paint(&tft);
}
