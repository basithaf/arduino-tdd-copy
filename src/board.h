#ifndef _BOARD_H_
#define _BOARD_H_

#include <stdint.h>
#include <string.h>
#include "rules.h"

#define BOARD_WIDTH 64
#define BOARD_HEIGHT 32
extern bool Current_Generation_Board[BOARD_WIDTH][BOARD_HEIGHT];

void setCell(uint8_t x, uint8_t y, bool value);
bool getCell(uint8_t x, uint8_t y);

uint8_t checkCellNeighbors(uint8_t x, uint8_t y);

void calculateNextGeneration();

#endif