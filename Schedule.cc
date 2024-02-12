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

// TODO: WTF is this shit, also use iomanip apparently
// maybe make helper to print line break
// the time box is a 9ch x 3ln unit
// horizontal line is 104ch long
// 5ch space for labels, then 10ch for data
// blocks are 15ch wide
// 3 ch gap between end of one block and start of next
// perhaps 1ch padding on both sides, then 1 ch space between blocks
// 4ch space into a block before printing date
// 3ch space between start of first block and the time box
// maybe use a case statement for how the line printed is formatted
void Schedule::print(){
    cout << endl << "   Schedule for current term: " << term << endl << endl;
    printHorizontalLine();
    cout << "|" + string(12,' ');



}

void Schedule::clear(){
    for(int i = 0; i < NUM_DAYS; i++){
        for (int j = 0; j < NUM_SLOTS; j++){
            courses[i][j] = nullptr;
        }
    }
}

string Schedule::getTerm(){
    return term;
}

// helper to print line, maybe remove if using iomanip
void Schedule::printHorizontalLine(){
    cout << string(104, '-') << endl;
}