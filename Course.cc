#include <string>
#include <iostream>
#include <iomanip>

#include "Course.h"

/// @brief default constructor for Course class
/// @param t , term
/// @param s ,subject
/// @param c , code
/// @param sec ,section
/// @param inst , instructor
/// @param d , day
/// @param hrs 
/// @param mins 
Course::Course(string t, string s, int c, char sec, string inst, LectDaysType d, int hrs, int mins){
  term = t;
  subject = s;
  code = c;
  section = sec;
  instructor = inst;
  days = d;
  time = new Time(hrs, mins);
}

/// @brief deletes dynamic time object
Course::~Course(){
  delete time;
}

/// @brief computes the days cresponding to this
/// @param day1 , first day return
/// @param day2 , second day return
/// @return , true if successful, else false
bool Course::computeDays(WeekDayType &day1, WeekDayType &day2){
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

/// @brief computes the time for this given a timeslot
/// @param slot , the timeslot to assign to this
/// @return ,true if success, else false
bool Course::computeSlot(TimeSlotType &slot){
  return time->computeSlot(slot);
}

bool Course::lessThan(Course* course)
{ 
  if (term < course->term)  {
    return true;
  }
  if (term > course->term)  {
    return false;
  }

  if(subject < course->subject){
    return true;
  }

  if (subject > course->subject)  {
    return false;
  }

  if (code < course->code)  {
    return true;
  }
  if (code > course->code)  {
    return false;
  }

  if (section < course->section)  {
    return true;
  }

  if (section > course->section)  {
    return false;
  }

  if (instructor < course->instructor)  {
    return true;
  }

  return false;
}
/// @brief prints terms
void Course::print(){
  cout << id << "  Term: " << term << "   " << subject << " " << code << section << "  ";
  printDays();
  cout << " ";
  time->print();
  cout << "   Instr: " << instructor << endl;
}

/// @brief prints the days string corresponding to this
void Course::printDays(){
  switch ((int)days)
  {
  case 0:
    cout << "MW";
    break;
  case 1:
    cout << "TR";
    break;

  case 2:
    cout << "WF";
    break;

  case 3:
    cout << "NA";
    break;
  }
}

int Course::getId(){
  return id;
}

string Course::getTerm(){
  return term;
}

string Course::getInstructor(){
  return instructor;
}

string Course::getCourse(){
  return (subject + " " + to_string(code) + "-" + section);
}

void Course::setId(int i){
  id = i;
}