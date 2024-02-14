#pragma once
#ifndef SCHOOL_H
#include <iostream>
#include <iomanip>
#include <string>

#include "Course.h"
#include "CourseArray.h"
#include "defs.h"

using namespace std;

class School
{

public:
    School(string = "N/A");
    ~School();
    void addCourse(Course *);
    bool findCourse(int, Course **);
    void printCourse(string);

private:
    string name;
    CourseArray courses;
    int numCourses;
};

#endif