#include <iostream>
#include <iomanip>
#include <string>

#include "Schedule.h"

Schedule::Schedule(string t){
    term = t;
    Schedule::clear();
}

bool Schedule::addCourse(Course* course){

    if(course == nullptr){
        cout << endl << "in addCourse: course is a nullptr" << endl;
        return false;
    }
    if (course->getTerm() != term){
        cout << endl << "in addCourse: course is of wrong term" << endl;
        return false;
    }

    // calculates days in sched
    WeekDayType d1, d2;
    bool cd = course->computeDays(d1,d2);
    if (!cd){
        cout << endl << "in addCourse: error in computeDays" << endl;
        return false;
    }

    // calculates timeslot in sched
    TimeSlotType t;
    bool cs = course->computeSlot(t);

    if (!cs){
        cout << endl << "in addCourse: error in computeSlot" << endl;
        return false;
    }

    // Sets pointers in sched to pointer for course
    courses[d1][t] = course;
    courses[d2][t] = course;

    return true;
}

// TODO: WTF is this shit
void Schedule::print(){
    cout << endl << "   Schedule for current term: " << term << endl << endl;

}

void Schedule::clear(){
    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 7; j++){
            courses[i][j] = nullptr;
        }
    }
}

string Schedule::getTerm(){
    return term;
}