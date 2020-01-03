#include <gtest/gtest.h>
#include "board.h"

using namespace ::testing;

TEST(board, BoardCanBeSetTrue) {
    setCell(2, 3, true);
    EXPECT_EQ(getCell(2, 3), true); 
}

 TEST(board, BoardCanBeSetFalse) {
    setCell(3, 2, false);
    EXPECT_EQ(getCell(3, 2), false); 
}

TEST(board, CheckCellNeighborsCanSeeIfLeftNeighborIsAlive) {
    setCell(3, 2, true);
    EXPECT_EQ(checkCellNeighbors(4,2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfLeftNeighborIsDead) {
    setCell(3, 2, false);
    EXPECT_EQ(checkCellNeighbors(4,2), 0); 
}

TEST(board, CheckCellNeighborsCanSeeIfRightNeighborIsAlive) {
    setCell(5, 2, true);
    EXPECT_EQ(checkCellNeighbors(4,2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfLeftAndRightNeighborsAreAlive) {
    setCell(3, 2, true);
    setCell(5, 2, true);
    EXPECT_EQ(checkCellNeighbors(4,2), 2); 
}

TEST(board, CheckCellNeighborsCanSeeIfTopNeighborIsAlive) {
    setCell(4, 1, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfBottomNeighborIsAlive) {
    setCell(4, 3, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfBottomRightNeighborIsAlive) {
    setCell(5, 3, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfBottomLeftNeighborIsAlive) {
    setCell(3, 3, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfTopLeftNeighborIsAlive) {
    setCell(3, 1, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsCanSeeIfTopRightNeighborIsAlive) {
    setCell(5, 1, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 1); 
}

TEST(board, CheckCellNeighborsAddsAllLiveNeighbors) {
    setCell(5, 1, true);
    setCell(3, 3, true);
    setCell(4, 3, true);
    setCell(3, 2, true);
    setCell(5, 2, true);
    EXPECT_EQ(checkCellNeighbors(4, 2), 5); 
}

TEST(board, CheckCellNeighborsDoesNotExceedLeftTopBounds) {
    setCell(1, 1, true);
    EXPECT_EQ(checkCellNeighbors(0, 0), 1); 
}

TEST(board, CheckCellNeighborsDoesNotExceedRightBottomBounds) {
    setCell(BOARD_WIDTH - 2, BOARD_HEIGHT - 2, true);
    EXPECT_EQ(checkCellNeighbors(BOARD_WIDTH - 1, BOARD_HEIGHT - 1), 1); 
}

TEST(board, calculateNextGenerationGivesCorrectNextGeneration) {
    setCell(3, 3, true);
    setCell(4, 2, true);
    setCell(4, 4, true);

    calculateNextGeneration();

    EXPECT_EQ(getCell(3, 3), true);
    EXPECT_EQ(getCell(4, 3), true);
    EXPECT_EQ(getCell(4, 2), false);
    EXPECT_EQ(getCell(4, 4), false);

}

