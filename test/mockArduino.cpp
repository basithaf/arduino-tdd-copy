#include "Arduino.h"

long currentSeed;

long random(long) {
    return currentSeed;
}

long random(long, long){
    return currentSeed;
}

void randomSeed(unsigned long seed) {
    currentSeed = seed;
}