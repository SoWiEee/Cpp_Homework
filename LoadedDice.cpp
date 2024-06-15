#include <random>
#include "LoadedDice.h"

using std::rand;

// constructor
LoadedDice:: LoadedDice() : Dice() {}
LoadedDice:: LoadedDice(int numSides) : Dice(numSides) {}

int LoadedDice:: rollDice() const {
    if (rand() % 2 == 0) return numSides;
    else return Dice::rollDice();
}