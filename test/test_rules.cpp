#include <gtest/gtest.h>
#include "rules.h"

using namespace ::testing;

TEST(Rules, LiveCellWithZeroNeighborsDies) { 
    bool result = is_cell_alive_next_gen(true, 0);
    EXPECT_EQ(false, result);
 }

 TEST(Rules, LiveCellWithTwoNeighborsLives) {
     bool result = is_cell_alive_next_gen(true, 2);
     EXPECT_EQ(true, result);
 }

 TEST(Rules, LiveCellWIthThreeNeightborsLives) {
     bool result = is_cell_alive_next_gen(true, 3);
     EXPECT_EQ(true, result);
 }

 TEST(Rules, LiveCellWithFourNeighborsDies) {
     bool result = is_cell_alive_next_gen(true, 4);
     EXPECT_EQ(false, result);
 }

 TEST(Rules, DeadCellWithThreeNeighborsLives) {
     bool result = is_cell_alive_next_gen(false, 3);
     EXPECT_EQ(true, result);
 }

 TEST(Rules, DeadCellWithTwoNeighborsRemainsDead) {
     bool result = is_cell_alive_next_gen(false, 2);
     EXPECT_EQ(false, result);
 }