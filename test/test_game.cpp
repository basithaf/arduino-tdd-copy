#include <gtest/gtest.h>
#include "Arduino.h"

using namespace ::testing;

TEST(game, random_is_generated) {
    
    long seed = random(100L);

    EXPECT_EQ(seed, 42);
}

TEST(game, random2_is_generated) {
    
    long seed = random(89L, 13L);

    EXPECT_EQ(seed, 42);
}

TEST(game, random_seed_is_generated) {
    
    randomSeed(100L);
}