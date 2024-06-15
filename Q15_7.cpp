#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

int main(void) {
    LoadedDice die1(6), die2(6);
    for (int i = 0; i < 10; i++) {
        cout << "Roll " << i+1 << ": " << rollTwoDice(die1, die2) << endl;
    }
    return 0;
}
