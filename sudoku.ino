#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "tft.h"
#include "panel.h"
#include "welcome_screen.h"
#include "options_screen.h"

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

WelcomeScreen* wScreen;
OptionsScreen* oScreen;
Panel *screen;

int i = 0;

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);
  tft.setRotation(3);

  wScreen = new WelcomeScreen();
  wScreen->init(&tft);
  wScreen->addListener(&switchToOptionsScreen);

  oScreen = new OptionsScreen();
  oScreen->init(&tft);
  oScreen->addListener(&switchToWelcomeScreen);

  screen = wScreen;
}

void switchTo(Panel *panel) {
  screen = panel;
  screen->setDirty();
}

void switchToWelcomeScreen(int x, int y) {
  switchTo(wScreen);
}

void switchToOptionsScreen(int x, int y) {
  switchTo(oScreen);
}

void loop() {
  screen->paint(&tft);
  delay(250);
  i++;

  // TSPoint touchPoint = ts.getPoint();
  // if (touchPoint.z > ts.pressureThreshhold) {
  //   Serial.println("Touched");
  // }

  if (i%10 == 0) {
    if (screen == wScreen) {
      Serial.println("Switch: op");
      switchToOptionsScreen(0, 0);
    } else {
      Serial.println("Switch: wel");
      switchToWelcomeScreen(0, 0);
    }
    i = 0;
  }
}
