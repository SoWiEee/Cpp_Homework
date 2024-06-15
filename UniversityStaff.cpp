#include <string>
#include <iostream>
#include "UniversityStaff.h"

using namespace std;

class UniversityStaff {
public:
    // constructor
    UniversityStaff() : name("") {}
    UniversityStaff(string theName) : name(theName) {}
    UniversityStaff(const UniversityStaff& theObject) : name(theObject.name) {}
    string getName() const { return name; }

    // overlaoding
    UniversityStaff& operator=(const UniversityStaff& rtSide) {
        if (this == &rtSide) return *this;
        name = rtSide.name;
        return *this;
    }
    friend istream& operator>>(istream& is, UniversityStaff& staff) {
        is >> staff.name;
        return is;
    }
    friend ostream& operator<<(ostream& os, const UniversityStaff& staff) {
        os << staff.name;
        return os;
    }

private:
    string name;
};