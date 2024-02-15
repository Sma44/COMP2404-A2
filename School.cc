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

/// @brief adds course to the courseArray object
/// @param course , the course to add to the array
void School::addCourse(Course* course){
    courses.add(course);
}

/// @brief finds a given course in the array
/// @param id , id to match course with
/// @param course , returns the found course
/// @return , true if successfully found, else false
bool School::findCourse(int id, Course** course){
    bool ret = courses.find(id, course);
    return ret;
}

/// @brief prints the courses of a given term
/// @param term , the term to print for
void School::printCourse(string term){
    courses.print(term);
    cout << endl;
}

