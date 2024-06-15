#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "UniversityStaff.h"

using namespace std;

class Student: public UniversityStaff{
public:
// constructor
    Student();
    Student(string uniName, int regNum, UniversityStaff proctor);
    Student(const Student& other);
    
    // overloading
    Student& operator=(const Student& rtSide);

    // getter
    string getUniversityName() const;
    int getRegistrationNumber() const;
    UniversityStaff getProctor() const;

private:
    string universityName;
    int registrationNumber;
    UniversityStaff proctor;
};

#endif