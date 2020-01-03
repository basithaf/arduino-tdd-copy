#include "board.h"

bool Current_Generation_Board[BOARD_WIDTH][BOARD_HEIGHT];

void setCell(uint8_t x, uint8_t y, bool value){
    Current_Generation_Board[x][y] = value;
}

bool getCell(uint8_t x, uint8_t y){
    return Current_Generation_Board[x][y];
}

bool notAtLeftEdge(uint8_t x) {
    return x > 0;
}

bool notAtRightEdge(uint8_t x) {
    return x < (BOARD_WIDTH - 1);
}

bool notAtTopEdge(uint8_t y) {
    return y > 0;
}

bool notAtBottomEdge(uint8_t y) {
    return y < (BOARD_HEIGHT - 1);
}

bool isLeftNeighborAlive(uint8_t x, uint8_t y) {
    return notAtLeftEdge(x) && getCell(x - 1, y);
}

bool isRightNeighborAlive(uint8_t x, uint8_t y) {
    return notAtRightEdge(x) && getCell(x + 1, y);
}

bool isTopNeighborAlive(uint8_t x, uint8_t y) {
    return notAtTopEdge(y) && getCell(x, y - 1);
}

bool isBottomNeighborAlive(uint8_t x, uint8_t y) {
    return notAtBottomEdge(y) && getCell(x, y + 1);
}

bool isBottomRightNeighborAlive(uint8_t x, uint8_t y) {
    return notAtRightEdge(x) && notAtBottomEdge(y) && getCell(x + 1, y + 1);
}

bool isBottomLeftNeighborAlive(uint8_t x, uint8_t y) {
    return notAtLeftEdge(x) && notAtBottomEdge(y) && getCell(x - 1, y + 1);
}

bool isTopLeftNeighborAlive(uint8_t x, uint8_t y) {
    return notAtLeftEdge(x) && notAtTopEdge(y) && getCell(x - 1, y - 1);
}

bool isTopRightNeighborAlive(uint8_t x, uint8_t y) {
    return notAtRightEdge(x) && notAtTopEdge(y) && getCell(x + 1, y - 1);
}

uint8_t checkCellNeighbors(uint8_t x, uint8_t y) {
    uint8_t liveNeighbors = 0;

    if (isLeftNeighborAlive(x, y)) { liveNeighbors++; }
    if (isRightNeighborAlive(x, y)) { liveNeighbors++; }
    if (isTopNeighborAlive(x, y)) { liveNeighbors++; }
    if (isBottomNeighborAlive(x, y)) { liveNeighbors++; }
    if (isBottomRightNeighborAlive(x, y)) { liveNeighbors++; }
    if (isBottomLeftNeighborAlive(x, y)) { liveNeighbors++; }
    if (isTopLeftNeighborAlive(x, y)) { liveNeighbors++; }
    if (isTopRightNeighborAlive(x, y)) { liveNeighbors++; }

    return liveNeighbors;
}

void calculateNextGeneration() {
    bool next_gen[BOARD_WIDTH][BOARD_HEIGHT];

    for (uint8_t column = 0; column < BOARD_WIDTH; column++) {
        for (uint8_t row = 0; row < BOARD_HEIGHT; row++) {
            bool cellCurrentlyAlive = getCell(column, row);
            uint8_t liveNeighbors = checkCellNeighbors(column, row);
            bool cellAliveNextGen = is_cell_alive_next_gen(cellCurrentlyAlive, liveNeighbors);

            next_gen[column][row] = cellAliveNextGen;
        }
    }

    memcpy(Current_Generation_Board, next_gen, BOARD_HEIGHT * BOARD_WIDTH);
}