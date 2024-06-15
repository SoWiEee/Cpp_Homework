#include <string>
#include <iostream>
#include "UniversityStaff.h"

using namespace std;

// constructor
UniversityStaff:: UniversityStaff() : name("") {}
UniversityStaff:: UniversityStaff(string theName) : name(theName) {}
UniversityStaff:: UniversityStaff(const UniversityStaff& theObject) : name(theObject.name) {}
string UniversityStaff::getName() const { return name; }

// overlaoding
UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide) {
    if (this == &rtSide) return *this;
    name = rtSide.name;
    return *this;
}
istream& operator>>(istream& is, UniversityStaff& staff) {
    is >> staff.name;
    return is;
}
ostream& operator<<(ostream& os, const UniversityStaff& staff) {
    os << staff.name;
    return os;
}