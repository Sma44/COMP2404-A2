#ifndef SCHOOL_H
#include <iostream>
#include <iomanip>
#include <string>

#include "CourseArray.h"

using namespace std;

/// @brief responsible for the courses available in the school
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