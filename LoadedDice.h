#ifndef LAODEDDICE_H
#define LAODEDDICE_H

#include "Dice.h"

class LoadedDice: public Dice {
public:
    // constructor
    LoadedDice();
    LoadedDice(int numSides);
    virtual int rollDice() const;
};

#endif 