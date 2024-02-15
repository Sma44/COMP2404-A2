#pragma once
#ifndef COURSE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"
#include "defs.h"

class Course
{

public:
  Course(string = "N/A", string = "N/A", int = 0, char = 'Z', string = "N/A", LectDaysType = BAD_LECT_DAYS, int = 0, int = 0);
  ~Course();
  bool computeDays(WeekDayType &, WeekDayType &);
  bool computeSlot(TimeSlotType &);
  bool lessThan(Course *);
  void print();
  int getId();
  string getTerm();
  string getInstructor();
  string getCourse();
  void setId(int);

private:
  int id;
  string term;
  string subject;
  int code;
  char section;
  string instructor;
  LectDaysType days;
  Time* time;
  void printDays();
};

#endif