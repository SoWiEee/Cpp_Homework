#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "Student.h"

using namespace std;

// child class
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

int main(void) {
    UniversityStaff proctor("Tom");
    ScienceStudent student("University of XYZ", 12345, proctor, "Physics", "Undergraduate");
    cout << "University Name: " << student.getUniversityName() << endl;
    cout << "Registration Number: " << student.getRegistrationNumber() << endl;
    cout << "Proctor: " << student.getProctor().getName() << endl;
    cout << "Science Discipline: " << student.getScienceDiscipline() << endl;
    cout << "Course Type: " << student.getCourseType() << endl;
    return 0;
}