#include <iostream>
#include<string>
#include "UniversityStaff.h"
#include "Student.h"
#include "ScienceStudent.h"

class ScienceStudent : public Student {
public:
    // constructor
    ScienceStudent() : Student(), scienceDiscipline(""), courseType("") {}
    ScienceStudent(string uniName, int regNum, UniversityStaff proctor, string sciDiscipline, string courseType)
        : Student(uniName, regNum, proctor), scienceDiscipline(sciDiscipline), courseType(courseType) {}
    ScienceStudent(const ScienceStudent& other)
        : Student(other), scienceDiscipline(other.scienceDiscipline), courseType(other.courseType) {}
    
    // overloading
    ScienceStudent& operator=(const ScienceStudent& rtSide) {
        if (this == &rtSide) return *this;
        Student::operator=(rtSide);
        scienceDiscipline = rtSide.scienceDiscipline;
        courseType = rtSide.courseType;
        return *this;
    }

    // getter
    string getScienceDiscipline() const { return scienceDiscipline; }
    string getCourseType() const { return courseType; }

private:
    string scienceDiscipline;
    string courseType;
};