#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "tft.h"
#include "point.h"
#include "button.h"
#include "colors.h"
#include "component.h"

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);

  tft.fillScreen(BLACK);

  Button b1(10, 10, 200, 40);
  Button b2(10, 110, 300, 140);

  b1.addChild(&b2);

  b1.paint(&tft);
}


void loop() {
}