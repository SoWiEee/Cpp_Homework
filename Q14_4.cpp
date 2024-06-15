#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "Student.h"
#include "ScienceStudent.h"

using namespace std;

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