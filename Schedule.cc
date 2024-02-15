#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Schedule.h"

Schedule::Schedule(string t)
{
  term = t;
  // initialize to nullptrs
  for (int i = 0; i < NUM_DAYS; i++)
  {
    for (int j = 0; j < NUM_SLOTS; j++)
    {
      courses[i][j] = nullptr;
    }
  }
}

bool Schedule::addCourse(Course *course)
{

  if (course == nullptr)
  {
    cout << endl
         << "in addCourse: course is a nullptr" << endl;
    return false;
  }
  if (course->getTerm() != term)
  {
    cout << endl
         << "in addCourse: course is of wrong term" << endl;
    return false;
  }

  // calculates days in sched
  WeekDayType d1, d2;
  bool cd = course->computeDays(d1, d2);
  if (!cd)
  {
    cout << endl
         << "in addCourse: error in computeDays" << endl;
    return false;
  }

  // calculates timeslot in sched
  TimeSlotType t;
  bool cs = course->computeSlot(t);

  if (!cs)
  {
    cout << endl
         << "in addCourse: error in computeSlot" << endl;
    return false;
  }

  // Sets pointers in sched to pointer for course
  courses[d1][t] = course;
  courses[d2][t] = course;

  return true;
}

// TODO: WTF is this shit, broken
void Schedule::print()
{

  // print banner
  cout << left << setw(0) << setfill(' ') << endl << "   Schedule for current term: " << term << endl << endl;

  // since trying to print enums results in index instead, have to make seperate day array
  string days[] = {"MON", "TUE", "WED", "THU", "FRI"};

  // prints labels for days
  printHorizontalLine();
  cout << "|" << setfill(' '); // prints left side bar for label
  for (int i = 0; i < NUM_DAYS; i++)
  { // prints each day with padding
    cout << setw(18) << right << days[i];
  }
  cout << setw(14) << right << "|" << endl; // prints right side padding for label
  printHorizontalLine();                    // closes label

  // temp time to call print()s on
  Time t(0, 0);

  for (int i = 0; i < NUM_SLOTS; i++)
  { // for each timeslot row

    for (int j = 0; j < 3; j++)
    { // loop 3 times for each row
      switch (j)
      { // print date on first loop, then print spaces instead
      case 0:
        t.setFromSlot((TimeSlotType)i);
        cout << setfill(' ') << setw(2) << left << "|";
        t.print();
        cout << setfill(' ') << setw(2) << right << "|";
        cout << setfill(' ') << setw(4) << " "; // add 4 space padding before printing courses
        break;
      case 1:
      case 2:
        cout << setfill(' ') << setw(8) << left << "|";
        cout << setfill(' ') << setw(5) << left << "|"; // add 4 space padding
        break;
      }

      for (int k = 0; k < NUM_DAYS; k++)
      { // loop through every course in row
        if (courses[k][i] != nullptr)
        { // if entry exists
          switch (j)
          { // print the corresponding data per iteration
          case 0:
            cout << setfill(' ') << setw(18) << left << courses[k][i]->getCourse(); // label and data with padding
            break;
          case 1:
            cout << setfill(' ') << setw(5) << left << "CN:";                   // label
            cout << setfill(' ') << setw(13) << left << courses[k][i]->getId(); // data with padding
            break;
          case 2:
            cout << setfill(' ') << setw(5) << left << "Pr:";                           // label
            cout << setfill(' ') << setw(13) << left << courses[k][i]->getInstructor(); // data with padding
            break;
          }
        }
        else
        { // if a nullptr, just add padding as placeholder
          cout << setfill(' ') << string(18, ' ');
        }
      }
      // padding at the end of the row
      cout << setfill(' ') << setw(2) << right << "|" << endl;
    }

    // prints bottom horizontal line to enclose block
    printHorizontalLine();
  }
}

void Schedule::clear()
{
  for (int i = 0; i < NUM_DAYS; i++)
  {
    for (int j = 0; j < NUM_SLOTS; j++)
    {
      courses[i][j] = nullptr;
    }
  }
}

string Schedule::getTerm()
{
  return term;
}

// helper function
void Schedule::printHorizontalLine()
{
  cout << setw(104) << left << setfill('-') << "|";
  cout << setw(1) << setfill(' ') << "|" << endl;
}