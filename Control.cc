#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control(string name){
  school = new School(name);
  numScheds = 0;
}

Control::~Control(){
  delete school;
  //for (int i = 0; i < numScheds; i++) might not be needed
}


void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

bool Control::addSched(Schedule* sched){
  if (numScheds == MAX_ARR){
    return false;
  }
  scheds[numScheds] = sched;
  return true;
}

bool Control::findSched(string term, Schedule** sched){
  bool ret = false;
  for (int i = 0; i < numScheds; i++){
    if (scheds[i]->getTerm() == term){
      *sched = scheds[i];
      ret = true;
    }
  }
  return ret;
}


void Control::launch(){
  initCourses(school);
  int selection = 7;
  string term;
  int id;
  bool found = false;

  while(selection != 0){
    view.showMenu(selection);

    switch (selection){

    case 0: // (0) Exit
      break;

    case 1: // (1) Change current term
      view.printStr("enter a term: ");
      view.readStr(term);
      view.printStr("\n");
      found = false;


      for (int i = 0; i < numScheds; i++){
        if (scheds[i]->getTerm() == term){
          found = true;
          break;
        }
      }
      if(!found){
        Schedule* tempSched = new Schedule(term);
        scheds[numScheds] = tempSched;
      }
      break;

    case 2: // (2) View courses
      school->printCourse(term);
      break;

    case 3: // (3) View schedule
      found = false;
      for (int i = 0; i < numScheds; i++){
        if (scheds[i]->getTerm() == term){
          scheds[i]->print();
          found=true;
        }
        if (!found){
          view.printStr("no schedules match the provided term\n");
        }
      }
      break;

    case 4: // (4) Add course to schedule
      found = false;
      for(int i = 0; i < numScheds; i++){
        if (scheds[i]->getTerm() == term){
          found = true;
          view.printStr("enter the course id: ");
          view.readInt(id);
          view.printStr("\n");
          Course** course = nullptr; // make course
          bool cFound;
          cFound = school->findCourse(id, course);
          if(!cFound){
            view.printStr("cannot find course\n");
            break;
          }
          scheds[i]->addCourse(*course);
        }
      }
      if(!found){
        view.printStr("no schedules match the provided term. cannot add course\n");
      }
      
    case 5:
      found = false;
      for(int i = 0; i < numScheds; i++){
        if (scheds[i]->getTerm() == term){
          scheds[i]->clear();
          found = true;
          break;
        }
      }
      if(!found){
        view.printStr("schedule to clear is not found\n");
      }
    }


  }

}