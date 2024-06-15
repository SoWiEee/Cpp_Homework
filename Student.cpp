#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "Student.h"

using namespace std;

// constructor
Student:: Student() : universityName(""), registrationNumber(0), proctor() {}
Student:: Student(string uniName, int regNum, UniversityStaff proctor): universityName(uniName), registrationNumber(regNum), proctor(proctor) {}
Student:: Student(const Student& other): universityName(other.universityName), registrationNumber(other.registrationNumber), proctor(other.proctor) {}

// overloading
Student& Student:: operator=(const Student& rtSide) {
    if (this == &rtSide) return *this;
    universityName = rtSide.universityName;
    registrationNumber = rtSide.registrationNumber;
    proctor = rtSide.proctor;
    return *this;
}

// getter
string Student:: getUniversityName() const { return universityName; }
int Student:: getRegistrationNumber() const { return registrationNumber; }
UniversityStaff Student:: getProctor() const { return proctor; }
