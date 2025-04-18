#include <iostream>
#include "Course.h"
#include "LabCourse.h"
#include "Lecture.h"
using namespace std;

int main() {
    LabCourse labCourse("OOP", 1);
    Lecture lecture("Lecture", 3);
    labCourse.displayInfo();
    cout << "Grade: " << labCourse.calculateGrade() << endl;
    lecture.displayInfo();
    cout << "Grade: " << lecture.calculateGrade() << endl;
    return 0;
}

