#ifndef SCHEDULE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"

class Schedule{

    public:
        Schedule();
        bool addCourse(Course*);
        void print();
        void clear();

    private:
        string term;
        Course* courses[5][7];
        int courNum;

};


#endif