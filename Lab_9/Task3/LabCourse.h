#pragma once

#include "Course.h"
#include <iostream>
using namespace std;

class LabCourse : public Course {
    public:
    LabCourse(string courseCode, int credits) : Course(courseCode, credits) {}

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

    double calculateGrade() override {
        return credits * 2.0;
    }

};