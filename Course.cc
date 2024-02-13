#include <string>
#include <iostream>
#include <iomanip>

#include "Course.h"

Course::Course(string t, string s, int c, char sec, string inst, LectDaysType d, int hrs, int mins)
{
  term = t;
  subject = s;
  code = c;
  section = sec;
  instructor = inst;
  days = d;
  time = new Time(hrs, mins);
}

Course::~Course()
{
  delete time;
}

bool Course::computeDays(WeekDayType &day1, WeekDayType &day2)
{
  bool ret = false;
  switch (days)
  {
  case MON_WED:
    day1 = MON;
    day2 = WED;
    ret = true;
    break;
  case TUE_THU:
    day1 = TUE;
    day2 = THU;
    ret = true;
    break;
  case WED_FRI:
    day1 = WED;
    day2 = FRI;
    ret = true;
    break;
  case BAD_LECT_DAYS:
    day1 = day2 = BAD_WEEK_DAY;
    break;
  }
  return ret;
}

bool Course::computeSlot(TimeSlotType &slot)
{
  return time->computeSlot(slot);
}

// TODO: possibly refactor into cleaner implementation. also might not work
bool Course::lessThan(Course *course)
{

  if (subject < course->subject)
  {
    return true;
  }
  if (subject > course->subject)
  {
    return false;
  }

  if (code < course->code)
  {
    return true;
  }
  if (code > course->code)
  {
    return false;
  }

  if (term < course->term)
  {
    return true;
  }
  if (term > course->term)
  {
    return false;
  }

  if (instructor > course->instructor)
  {
    return false;
  }
  if (instructor < course->instructor)
  {
    return true;
  }

  if (section < course->section)
  {
    return true;
  }

  return false;
}

void Course::print()
{
  cout << id << "  Term: " << term << "   " << subject << " " << code << section << "  ";
  printDays();
  cout << " ";
  time->print();
  cout << "   Instr: " << instructor;
}

void Course::printDays()
{
  switch (days)
  {
  case MON_WED:
    cout << "MW";
    break;
  case TUE_THU:
    // idk what tr means maybe change it back to tt
    cout << "TR";
    break;

  case WED_FRI:
    cout << "WF";
    break;

  case BAD_WEEK_DAY:
    cout << "NA";
    break;
  }
}

int Course::getId()
{
  return id;
}

string Course::getTerm()
{
  return term;
}

string Course::getInstructor()
{
  return instructor;
}

// TODO: look into stringstream as alt to to_string
string Course::getCourse()
{
  return (subject + " " + to_string(code) + "-" + section);
}

void Course::setId(int i)
{
  id = i;
}