#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Schedule.h"

Schedule::Schedule(string t){
  term = t;
  clear();
}

bool Schedule::addCourse(Course *course){

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

  WeekDayType d1, d2;
  bool cd = course->computeDays(d1, d2);
  if (!cd)
  {
    cout << endl
         << "in addCourse: error in computeDays" << endl;
    return false;
  }

  TimeSlotType t;
  bool cs = course->computeSlot(t);

  if (!cs)
  {
    cout << endl
         << "in addCourse: error in computeSlot" << endl;
    return false;
  }

  courses[d1][t] = course;
  courses[d2][t] = course;

  return true;
}

void Schedule::print(){

  cout << left << setw(0) << setfill(' ') << endl << "   Schedule for current term: " << term << endl << endl;

  string days[] = {"MON", "TUE", "WED", "THU", "FRI"};

  
  printHorizontalLine();
  cout << "|" << setfill(' ');
  for (int i = 0; i < NUM_DAYS; i++)
  { 
    cout << setw(18) << right << days[i];
  }
  cout << setw(14) << right << "|" << endl; 
  printHorizontalLine();                    
  
  Time t(0, 0);

  for (int i = 0; i < NUM_SLOTS; i++){ 
    for (int j = 0; j < 3; j++){ 
      switch (j){ 
      case 0:
        t.setFromSlot((TimeSlotType)i);
        cout << setfill(' ') << setw(2) << left << "|";
        t.print();
        cout << setfill(' ') << setw(2) << right << "|";
        cout << setfill(' ') << setw(4) << " "; 
        break;
      case 1:
      case 2:
        cout << setfill(' ') << setw(8) << left << "|";
        cout << setfill(' ') << setw(5) << left << "|"; 
        break;
      }

      for (int k = 0; k < NUM_DAYS; k++){ 
        if (courses[k][i] != nullptr){ 
          switch (j){ 
          case 0:
            cout << setfill(' ') << setw(18) << left << courses[k][i]->getCourse();
            break;
          case 1:
            cout << setfill(' ') << setw(5) << left << "CN:";                   
            cout << setfill(' ') << setw(13) << left << courses[k][i]->getId(); 
            break;
          case 2:
            cout << setfill(' ') << setw(5) << left << "Pr:";                           
            cout << setfill(' ') << setw(13) << left << courses[k][i]->getInstructor(); 
            break;
          }
        }
        else{ 
          cout << setfill(' ') << string(18, ' ');
        }
      }
      cout << setfill(' ') << setw(2) << right << "|" << endl;
    }
    printHorizontalLine();
  }
}

void Schedule::clear(){
  for (int i = 0; i < NUM_DAYS; i++){
    for (int j = 0; j < NUM_SLOTS; j++){
      courses[i][j] = nullptr;
    }
  }
}

string Schedule::getTerm(){
  return term;
}

void Schedule::printHorizontalLine(){
  cout << setw(104) << left << setfill('-') << "|";
  cout << setw(1) << setfill(' ') << "|" << endl;
}