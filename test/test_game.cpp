#include <gtest/gtest.h>
#include "Arduino.h"

using namespace ::testing;

TEST(game, random_is_generated) {
    
    long randomNumber = random(100L);

    EXPECT_EQ(randomNumber, 0);
}

TEST(game, random2_is_generated) {
    
    long randomNumber = random(89L, 13L);

    EXPECT_EQ(randomNumber, 0);
}

TEST(game, random_seed_is_generated) {
    randomSeed(100L);

    long randomNumber = random(1000L);

    EXPECT_EQ(randomNumber, 100L);
}