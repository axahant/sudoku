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

byte beginnerSudoku[] = { 0, 3, 2, 5, 9, 0, 7, 8, 6,
                          7, 6, 5, 2, 4, 8, 9, 3, 1,
                          8, 1, 0, 3, 6, 7, 2, 0, 5,
                          6, 7, 5, 3, 2, 8, 9, 1, 4,
                          1, 8, 3, 6, 0, 4, 5, 2, 7,
                          9, 2, 4, 5, 7, 1, 6, 8, 3,
                          8, 0, 7, 1, 4, 9, 0, 5, 3,
                          3, 1, 9, 8, 5, 2, 4, 7, 6,
                          4, 5, 2, 0, 3, 6, 1, 9, 0 };

byte intermediateSudoku[] = { 5, 0, 6, 0, 0, 8, 0, 0, 0,
                              3, 8, 2, 0, 4, 6, 5, 7, 9,
                              0, 0, 1, 0, 0, 0, 0, 0, 4,
                              3, 0, 0, 0, 0, 0, 2, 6, 5,
                              2, 0, 8, 9, 0, 5, 7, 0, 4,
                              6, 5, 7, 0, 0, 0, 0, 0, 9,
                              6, 0, 0, 0, 0, 0, 7, 0, 0,
                              4, 2, 7, 8, 5, 0, 6, 9, 3,
                              0, 0, 0, 2, 0, 0, 4, 0, 8 };

byte advancedSudoku[] = { 0, 5, 6, 0, 0, 0, 9, 7, 0,
                          0, 0, 0, 0, 7, 0, 0, 0, 0,
                          4, 7, 0, 0, 0, 0, 0, 8, 3,
                          6, 0, 0, 5, 2, 7, 3, 0, 0,
                          2, 5, 8, 4, 0, 3, 6, 9, 7,
                          0, 0, 7, 8, 6, 9, 0, 0, 5,
                          1, 9, 0, 0, 0, 0, 0, 6, 3,
                          0, 0, 0, 0, 3, 0, 0, 0, 0,
                          0, 5, 8, 0, 0, 0, 0, 9, 0 };

byte aceSudoku[] = { 6, 0, 0, 0, 0, 0, 8, 0, 0,
                     5, 7, 0, 0, 6, 4, 0, 2, 1,
                     0, 1, 0, 8, 2, 0, 3, 0, 0,
                     0, 2, 0, 3, 0, 0, 0, 0, 0,
                     0, 3, 7, 0, 0, 0, 4, 8, 0,
                     0, 0, 0, 0, 0, 6, 0, 3, 0,
                     0, 0, 9, 0, 8, 7, 0, 5, 0,
                     7, 4, 0, 1, 5, 0, 0, 9, 6,
                     0, 0, 2, 0, 0, 0, 0, 0, 1 };

struct Cell {
  byte value = 0;
  bool editable = true; 
};

Cell sudoku[81];

byte solvingCellIndex = 0;

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
  } else if (screenIndex == 1 && solvingCellIndex >=0 && solvingCellIndex < 81) {
    byte z = solvingCellIndex / 9;
    byte x = (solvingCellIndex % 9) / 3;
    byte y = (solvingCellIndex % 9) % 3;

    if (!isCellEditable(z, x, y)) {
      solvingCellIndex++;
    } else {
      byte cellValue = getCellValue(z, x, y);

      if (cellValue == 0 || (!isCellValid(z, x, y) && cellValue < 9)) {
        setCellValue(z, x, y, cellValue + 1, true);

        if (isCellValid(z, x, y)) {
          solvingCellIndex++;
        }        
      } else {
        setCellValue(z, x, y, 0, true);
        do {
          solvingCellIndex--;
          z = solvingCellIndex / 9;
          x = (solvingCellIndex % 9) / 3;
          y = (solvingCellIndex % 9) % 3;
        } while (!isCellEditable(z, x, y) && solvingCellIndex > 0);
        
        cellValue = getCellValue(z, x, y);
        if (solvingCellIndex >= 0 && cellValue < 9) { 
          setCellValue(z, x, y, cellValue + 1, true);
          if (isCellValid(z, x, y)) {
            solvingCellIndex++;
          }
        }
      }
    }
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

void initSudoku() {
  //emptySudoku();
  copySudoku(aceSudoku);
}

void emptySudoku() {
  for (byte z = 0; z < 9; z++) {
    for (byte x = 0; x < 3; x++) {
      for (byte y = 0; y < 3; y++) {
        setCellValue(z, x, y, 0, true);
      }
    }
  }
}

void copySudoku(byte *v) {
  for (byte i = 0; i < 81; i++) {
    byte z = i / 9;
    byte x = (i % 9) / 3;
    byte y = (i % 9) % 3;
    setCellValue(z, x, y, v[i], v[i] == 0);
  }
}

void setCellValue(byte z, byte x, byte y, byte number, bool editable) {
  byte index = toArrayIndex(z, x, y);
  sudoku[index].value = number;
  sudoku[index].editable = editable;
  showCell(z, x, y); 
}

byte getCellValue(byte z, byte x, byte y) {
  byte index = toArrayIndex(z, x, y);
  return sudoku[index].value;
}

bool isCellEditable(byte z, byte x, byte y) {
  byte index = toArrayIndex(z, x, y);
  return sudoku[index].editable;
}

void showSudoku() {
  for (byte i = 0; i < 81; i++) {
    byte z = i / 9;
    byte x = (i % 9) / 3;
    byte y = (i % 9) % 3;
    showCell(z, x, y);
  }
}

void showCell(byte z, byte x, byte y) {
  byte side = tft.height();
  byte arrayIndex = toArrayIndex(z, x, y);
  byte cellX = (((z % 3) * 3 + y) * side/9);
  byte cellY = (((z / 3) * 3 + x) * side/9); 
  tft.fillRect(cellX + 1, cellY + 1, side/9 - 2, side/9 - 2, BLUE);
  tft.setCursor(cellX + 1, cellY + 1);
  tft.setTextSize(1);
  tft.setTextColor(BLACK);
  // tft.print(x);
  // tft.print(",");
  // tft.print(y);
  // tft.setCursor(cellX + 1, cellY + side/9 - 8);
  // tft.print(toArrayIndex(z, x, y));
  if (sudoku[arrayIndex].value != 0) {
    tft.setCursor(cellX + 12, cellY + 10);

    if (isCellValid(z, x, y)) {
      if (sudoku[arrayIndex].editable) {
        tft.setTextColor(WHITE);
      } else {
        tft.setTextColor(BLACK);
      }
    } else {
      tft.setTextColor(RED);
    }

    tft.print(sudoku[arrayIndex].value);
  }
}

bool isCellValid(byte z, byte x, byte y) {
  if (getCellValue(z, x, y) > 0 && isCellEditable(z, x, y)) {
    return isGridValid(z) & isColumnValid(z, y) & isRowValid(z, x);
  } else {
    return true;
  }
}

byte toArrayIndex(byte z, byte x, byte y) {
  return x * 3 + y + (z * 9);
}

void highlightCell(byte z, byte x, byte y) {
  byte side = tft.height();
  byte cellX = (((z % 3) * 3 + y) * side/9);
  byte cellY = (((z / 3) * 3 + x) * side/9); 
  tft.drawRect(cellX, cellY, side/9, side/9, RED);
}

void drawString(String s, byte x, byte y, byte size, unsigned int color) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(s);
}

bool isGridValid(byte z) {
  byte numbersInGridCount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  for (byte x = 0; x < 3; x++) {
    for (byte y = 0; y < 3; y++) {
      byte value = getCellValue(z, x, y);
      if (value > 0) {
        numbersInGridCount[value - 1]++;
      }
    }
  }

  return onlyOnce(numbersInGridCount);
}

bool isRowValid(byte z, byte x) {
  byte numbersInRowCount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  byte sZ = (z / 3) * 3;
  for (byte lZ = sZ; lZ < sZ + 3; lZ++) {
    for (byte y = 0; y < 3; y++) {
      byte value = getCellValue(lZ, x, y);
      if (value > 0) {
        numbersInRowCount[value - 1]++;
      }
    }
  }

  return onlyOnce(numbersInRowCount);
}

bool isColumnValid(byte z, byte y) {
  byte numbersInColCount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  byte sZ = z % 3;
  for (byte lZ = sZ; lZ < 9; lZ+=3) {
    for (byte x = 0; x < 3; x++) {
      byte value = getCellValue(lZ, x, y);
      if (value > 0) {
        numbersInColCount[value - 1]++;
      }
    }
  }

  return onlyOnce(numbersInColCount);
}

bool onlyOnce(byte *numbersCount) {
  bool valid = true;
  for (byte n = 0; n < 9; n++) {
    valid = valid & numbersCount[n] < 2;
  }

  return valid;
}