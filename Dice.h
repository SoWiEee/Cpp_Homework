#ifndef DICE.H
#define DICE.H

class Dice {
public:
    // constructor
    Dice();
    Dice(int numSides);
    virtual int rollDice() const;

protected:
    int numSides;
};

// chlid class
class LoadedDice : public Dice {
public:
    // constructor
    LoadedDice();
    LoadedDice(int numSides);
    
    virtual int rollDice() const;
};

#endif