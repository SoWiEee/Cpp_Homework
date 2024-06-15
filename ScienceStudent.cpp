#include <iostream>
#include<string>
#include "UniversityStaff.h"
#include "Student.h"
#include "ScienceStudent.h"

// constructor
ScienceStudent:: ScienceStudent(): Student(), scienceDiscipline(""), courseType("") {}
ScienceStudent:: ScienceStudent(string uniName, int regNum, UniversityStaff proctor, string sciDiscipline, string courseType)
    : Student(uniName, regNum, proctor), scienceDiscipline(sciDiscipline), courseType(courseType) {}
ScienceStudent:: ScienceStudent(const ScienceStudent& other): Student(other), scienceDiscipline(other.scienceDiscipline), courseType(other.courseType) {}

// overloading
ScienceStudent& ScienceStudent:: operator=(const ScienceStudent& rtSide) {
    if (this == &rtSide) return *this;
    Student:: operator=(rtSide);
    scienceDiscipline = rtSide.scienceDiscipline;
    courseType = rtSide.courseType;
    return *this;
}

// getter
string ScienceStudent:: getScienceDiscipline() const { return scienceDiscipline; }
string ScienceStudent:: getCourseType() const { return courseType; }