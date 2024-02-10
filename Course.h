#ifndef COURSE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"
#include "defs.h"

class Course{

    public:
        Course(int=0,string="N/A",string="N/A",int=0,char='Z',string="N/A", LectDaysType=BAD_LECT_DAYS);
        bool computeDays(WeekDayType&);
        bool computeSlot(TimeSlotType&);
        bool lessThan(Course*);
        void print();
        
    private:
        int id;
        string term;
        string subject;
        int code;
        char section; 
        string instructor;
        LectDaysType days;
        Time start; 

};


#endif