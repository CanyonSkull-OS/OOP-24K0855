#pragma once

#include "Course.h"
#include <iostream>
using namespace std;

class Lecture : public Course {
    public:
    Lecture(string courseCode, int credits) : Course(courseCode, credits) {}

    double calculateGrade() override {
        return credits * 2.0;
    }

    void displayInfo() override {
        cout << "Lecture: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

};