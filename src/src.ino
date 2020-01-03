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

  randomBoard();

  drawBoard();
}

void loop() {
    delay(200);
    calculateNextGeneration();
    drawBoard();
}

void drawBoard() {
    for(uint8_t column = 0; column < BOARD_WIDTH; column++) {
      for(uint8_t row = 0; row < BOARD_HEIGHT; row++) {
          if(getCell(column, row)) {
              matrix.drawPixel(column, row, matrix.Color333(0, 4, 0));
          }
          else {
              matrix.drawPixel(column, row, matrix.Color333(0, 0, 0));
          }
      }
  }
}

void randomBoard() {
    randomSeed(analogRead(8));

    for(uint8_t column = 0; column < BOARD_WIDTH; column++) {
      for(uint8_t row = 0; row < BOARD_HEIGHT; row++) {
          long randomNumber = random(0, 100);
          if (randomNumber > 50) {
              setCell(column, row, true);
          }
      }
  }
}