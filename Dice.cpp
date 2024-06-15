#include<ctime>
#include<random>
#include "Dice.h"

using namespace std;

// constructor
Dice:: Dice(): numSides(6) { srand(time(NULL)); }
Dice:: Dice(int numSides): numSides(numSides) { srand(time(NULL)); }

int Dice::rollDice() const { return (rand() % numSides) + 1; }
