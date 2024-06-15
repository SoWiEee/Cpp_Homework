#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

class Creature {
private:
    int strength;
    int hitpoints;

public:
    // constructor
    Creature(): strength(10), hitpoints(10) {};
    Creature(int newStrength, int newHit){
        strength = newStrength;
        hitpoints = newHit;
    }

    // getter
    int getStren(){
        return strength;
    }
    int getHit(){

    }
    virtual string getSpecies() = 0;
    virtual int getDamage(){
        // All creatures inflict damage, which is a random number up to their strength
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

class Demon: public Creature{
    public:
    Demon(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    string getSpecies() { return "Demon"; }
    int getDamage() {
        int damage = Creature::getDamage();
        // Demons can inflict damage of 50 with a 5% chance
        if ((rand() % 100) < 5) {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
};


class Human: public Creature{
public:
    Human(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    string getSpecies() { return "Human"; }
};

class Elf: public Creature{
public:
    // constructor
    Elf(int newStrength, int newHit) : Creature(newStrength, newHit) {}
    string getSpecies() { return "Elf"; }
    int getDamage(){
        int base = (rand() % getStren()) + 1;
        // double damage
        if(rand() % 10 == 0){
            cout << "Magical attack inflicts " << base <<" additional damage points!" << endl;
            return base*2;

        }
    }
};

class CyberDemon: public Demon{
public:
    CyberDemon(int newStrength, int newHit) : Demon(newStrength, newHit) {}
    string getSpecies() { return "Cyberdemon"; }

    int getDamage(){
        int base = (rand() % getStren()) + 1;
        cout << getSpecies() << " attacks for " << base << " points!" << endl;
        if((rand( ) % 100) < 5){
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            return base + 50;

        }
        return base;
    }
};
class Balrog: public Demon{
public:
    Balrog(int newStrength, int newHit) : Demon(newStrength, newHit) {}
    string getSpecies() { return "Balrog"; }
    int getDamage(){
        int damage = Demon::getDamage();
        // attack twice
        int damage2 = (rand() % getStren()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        return damage + damage2;
    }
};

int main(void){
    srand(time(0));
    Human h(30, 40);
    Elf e(50, 50);
    CyberDemon c(60, 60);
    Balrog b(70, 70);

    for (int i = 0; i < 10; i++) {
        h.getDamage();
        e.getDamage();
        c.getDamage();
        b.getDamage();
    }

    system("pause");
    return 0;
}

