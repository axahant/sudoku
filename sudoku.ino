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

struct Cell {
  byte value = 0;
  byte triedValues[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
};

Cell sudoku[81];

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
  initSudoku();
}

void emptySudoku() {
  for (byte z = 0; z < 9; z++) {
    for (byte x = 0; x < 3; x++) {
      for (byte y = 0; y < 3; y++) {
        setCellValue(z, x, y, 1);
      }
    }
  }
}

void initSudoku() {
  emptySudoku();
}

Cell getCell(byte x, byte y) {
  byte index = x * 9 + y;
  return sudoku[index];
}

byte getCellValue(byte x, byte y) {
  return getCell(x, y).value;
}

void setCellValue(byte z, byte x, byte y, byte number) {
  byte index = toArrayIndex(z, x, y);
  sudoku[index].value = number;
  showCell(z, x, y, WHITE); 
}

void showSudoku() {
  for(byte n = 0; n < 81; n++) {
    byte z = n / 9;
    byte x = (n % 9) % 3;
    byte y = (n % 9) / 3;
    showCell(z, x, y, WHITE);
  }
}

void showCell(byte z, byte x, byte y, int color) {
  byte side = tft.height();
  byte arrayIndex = toArrayIndex(z, x, y);
  byte cellX = (((z % 3) * 3 + x) * side/9);
  byte cellY = (((z / 3) * 3 + y) * side/9); 
  tft.fillRect(cellX + 1, cellY + 1, side/9 - 2, side/9 - 2, BLUE);
  tft.setCursor(cellX + 1, cellY + 1);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.print(x);
  tft.print(",");
  tft.print(y);
  tft.setCursor(cellX + 1, cellY + side/9 - 8);
  tft.print(toArrayIndex(z, x, y));
  if (sudoku[arrayIndex].value != 0) {
    tft.setCursor(cellX + 12, cellY + 10);
    tft.setTextColor(color);
    tft.print(sudoku[arrayIndex].value);
  }
}

byte toArrayIndex(byte z, byte x, byte y) {
  return x * 3 + y + (z * 9);
}

void highlightCell(byte z, byte x, byte y) {
  byte side = tft.height();
  byte cellX = (((z % 3) * 3 + x) * side/9);
  byte cellY = (((z / 3) * 3 + x) * side/9); 
  tft.drawRect(cellX, cellY, side/9, side/9, RED);
}

void drawString(String s, byte x, byte y, byte size, unsigned int color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(s);
}