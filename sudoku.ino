#include <Elegoo_GFX.h>    
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#include "tft.h"
#include "point.h"
#include "button.h"
#include "colors.h"
#include "component.h"
#include "grid_layout.h"

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  
  uint16_t identifier = 0x9341;
  tft.begin(identifier);

  tft.fillScreen(BLACK);

  Button parent;
  Button b1;
  Button b2;
  
  parent.addChild(&b1);
  parent.addChild(&b2);
  Serial.println(tft.width());
  Serial.println(tft.height());

  Rectangle tftRectangle(0, 0, tft.width() - 1, tft.height() - 1);
  GridLayout layout(tftRectangle, 6, 6);
  layout.layout(&parent);

  parent.paintChildren(&tft);
}


void loop() {
}