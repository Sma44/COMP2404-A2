#ifndef SCHOOL_H
#include <iostream>
#include <iomanip>
#include <string>

#include "Course.h"
#include "defs.h"

using namespace std;

class School
{

public:
    School(string = "N/A");
    void addCourse(Course *);
    bool findCourse(int, Course **);
    void printCourse(string);

private:
    string name;
    // maybe need pointer array instead
    Course courses[MAX_ARR];
    int numCourses;
};

#endif