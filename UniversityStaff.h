#ifndef UNIVERSITYSTAFF.H
#define UNIVERSITYSTAFF.H

#include <string>
#include <iostream>

using namespace std;

class UniversityStaff {
public:
    // constructor
    UniversityStaff();
    UniversityStaff(string theName);
    UniversityStaff(const UniversityStaff& theObject);
    string getName() const;

    // overlaoding
    UniversityStaff& operator=(const UniversityStaff& rtSide);
    friend istream& operator>>(istream& is, UniversityStaff& staff);
    friend ostream& operator<<(ostream& os, const UniversityStaff& staff);

private:
    string name;
};

#endif