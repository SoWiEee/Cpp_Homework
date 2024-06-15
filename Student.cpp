#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "Student.h"

using namespace std;

class Student {
public:
// constructor
    Student() : universityName(""), registrationNumber(0), proctor() {}
    Student(string uniName, int regNum, UniversityStaff proctor)
        : universityName(uniName), registrationNumber(regNum), proctor(proctor) {}
    Student(const Student& other)
        : universityName(other.universityName), registrationNumber(other.registrationNumber), proctor(other.proctor) {}
    
    // overloading
    Student& operator=(const Student& rtSide) {
        if (this == &rtSide) return *this;
        universityName = rtSide.universityName;
        registrationNumber = rtSide.registrationNumber;
        proctor = rtSide.proctor;
        return *this;
    }

    // getter
    string getUniversityName() const { return universityName; }
    int getRegistrationNumber() const { return registrationNumber; }
    UniversityStaff getProctor() const { return proctor; }

private:
    string universityName;
    int registrationNumber;
    UniversityStaff proctor;
};