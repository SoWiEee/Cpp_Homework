#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include <iostream>
#include<string>
#include "UniversityStaff.h"
#include "Student.h"

class ScienceStudent : public Student {
public:
    // constructor
    ScienceStudent();
    ScienceStudent(string uniName, int regNum, UniversityStaff proctor, string sciDiscipline, string courseType);
    ScienceStudent(const ScienceStudent& other);
    
    // overloading
    ScienceStudent& operator=(const ScienceStudent& rtSide);

    // getter
    string getScienceDiscipline() const;
    string getCourseType() const;

private:
    string scienceDiscipline;
    string courseType;
};

#endif