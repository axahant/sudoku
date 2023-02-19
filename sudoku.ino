#include <TouchScreen.h>
#include <Elegoo_TFTLCD.h>

#include "tft.h"
#include "colors.h"

static TouchScreen ts(XP, YP, XM, YM, 300);
static Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
bool dirty = true;
// 0 - Welcome Screen
// 1 - Sudoku Screen
byte screenIndex = 0;

void setup(void) {
  Serial.begin(9600);

  tft.reset();
  
  tft.begin(0x9341);
  tft.setRotation(3);
}

void loop() {
  if (dirty) {
    if (screenIndex == 0) {
      drawWelcomeScreen();
    }
    if (screenIndex == 1) {
      drawSudokuScreen();
    }

    dirty = false;
  }
}

void drawWelcomeScreen() {
  tft.fillScreen(BLUE);
  drawString(F("Welcome"), 60, 30, 5, YELLOW);  
  drawString(F("Arduino Sudoku"), 35, 100, 3, WHITE);
  drawString(F("Extended Project"), 65, 135, 2, YELLOW);
  drawString(F("Axahant Dubey"), 85, 175, 2, WHITE);
  drawString(F("Year 7 Hawks"), 90, 195, 2, GREEN);
  delay(2000);
  screenIndex = 1;
  dirty = true; 
}

void drawSudokuScreen() {
  tft.fillScreen(BLUE);
  int side = tft.height();
  tft.drawRect(0, 0, side, side, WHITE);
  for(int n=1; n<=9; n++) {
    int color = BLACK;
    if (n%3 == 0) {
      color = WHITE; 
    }
    tft.drawFastVLine(n * side/9, 1, side - 2, color);
    tft.drawFastHLine(1, n * side/9, side - 2, color);
  }
  writeInCell(side, 2, 2, F("5"), WHITE);
  writeInCell(side, 2, 2, F("6"), WHITE);
}

void writeInCell(int side, byte x, byte y, String number, int color) {
  int cellX = (x * side/9);
  int cellY = (y * side/9); 
  tft.fillRect(cellX + 1, cellY + 1, side/9 - 2, side/9 - 2, BLUE);
  tft.setCursor(cellX + 8, cellY + 8);
  tft.setTextColor(color);
  tft.print(number);
}

void drawString(String s, int x, int y, int size, unsigned int color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(s);
}
