#include <RGBmatrixPanel.h>
#include "board.h"

#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {

  matrix.begin();

  // fill the screen with 'black'
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  setCell(3, 3, true);
  setCell(4, 2, true);
  setCell(4, 4, true);

  for(uint8_t c = 0; c < BOARD_WIDTH; c++) {
      for(uint8_t r = 0; r < BOARD_HEIGHT; r++) {
          if(getCell(c, r)) {
              matrix.drawPixel(c, r, matrix.Color333(7, 7, 7));
          }
      }
  }
  
}

void loop() {
}
