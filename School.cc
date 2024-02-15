#include <iostream>
#include <iomanip>
#include <string>

#include "School.h"

using namespace std;

School::School(string n){
    name = n;
    numCourses = 0;
}

School::~School(){}

void School::addCourse(Course* course){
    courses.add(course);
}

bool School::findCourse(int id, Course** course){
    bool ret = courses.find(id, course);
    return ret;
}

void School::printCourse(string term){
    courses.print(term);
    cout << endl;
}

