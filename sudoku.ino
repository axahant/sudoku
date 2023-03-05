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
  for (byte x = 0; x < 9; x++) {
    for (byte y = 0; y < 9; y++) {
      setCellValue(x, y, 1);
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

void setCellValue(byte x, byte y, byte number) {
  byte index = x * 9 + y;
  sudoku[index].value = number;
  if (number == 0) {
    for (byte i = 0; i < 9; i++) {
      sudoku[index].triedValues[i] = 0;
    }
  } else {
    byte idx = 0;
    sudoku[index].triedValues[number - 1] = number;
  }
  showCell(x, y, WHITE); 
}

void showSudoku() {
  for(byte n = 0; n < 81; n++) {
    byte x = n / 9;
    byte y = n % 9;
    showCell(x, y, WHITE);
  }
}

void showCell(byte x, byte y, int color) {
  byte side = tft.height();
  byte arrayIndex = toArrayIndex(x, y);
  byte cellX = (x * side/9);
  byte cellY = (y * side/9); 
  tft.fillRect(cellX + 1, cellY + 1, side/9 - 2, side/9 - 2, BLUE);
  tft.setCursor(cellX + 1, cellY + 1);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  tft.print(x);
  tft.print(",");
  tft.print(y);
  tft.setCursor(cellX + 1, cellY + side/9 - 8);
  tft.print(toArrayIndex(x, y));
  if (sudoku[arrayIndex].value != 0) {
    tft.setCursor(cellX + 12, cellY + 10);
    tft.setTextColor(color);
    tft.print(sudoku[arrayIndex].value);
  }
}

byte toArrayIndex(byte x, byte y) {
  return x * 9 + y;
}

byte toArrayIndex(byte gX, byte gY, byte x, byte y) {
  byte cellX = (gX * 3 + x);
  byte cellY = (gY * 3 + y);
  byte arrayIndex = cellX * 9 + cellY;
  return arrayIndex;
}

void highlightCell(byte x, byte y) {
  byte side = tft.height();
  byte cellX = (x * side/9);
  byte cellY = (y * side/9); 
  tft.drawRect(cellX, cellY, side/9, side/9, RED);
}

void drawString(String s, byte x, byte y, byte size, unsigned int color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(s);
}