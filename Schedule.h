#ifndef SCHEDULE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"

/// @brief responsible for the state of a schedule, storing pointers to the courses for each slot
class Schedule
{

public:
  Schedule(string = "N/A");
  bool addCourse(Course *);
  void print();
  void clear();
  string getTerm();

private:
  string term;
  Course *courses[NUM_DAYS][NUM_SLOTS];
  void printHorizontalLine();
};

#endif