#include<ctime>
#include<random>

using namespace std;

class Dice {
public:
    // constructor
    Dice() : numSides(6) { srand(time(NULL)); }
    Dice(int numSides) : numSides(numSides) { srand(time(NULL)); }
   
    virtual int rollDice() const { return (rand() % numSides) + 1; }

protected:
    int numSides;
};

// chlid class
class LoadedDice : public Dice {
public:
    // constructor
    LoadedDice() : Dice() {}
    LoadedDice(int numSides) : Dice(numSides) {}
    
    virtual int rollDice() const {
        if (rand() % 2 == 0) return numSides;
        else return Dice::rollDice();
    }
};