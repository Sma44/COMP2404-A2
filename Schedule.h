#ifndef SCHEDULE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "defs.h"

class Schedule{

    public:
        Schedule(string="N/A");
        // might need destructor??
        bool addCourse(Course*);
        void print();
        void clear();
        string getTerm();

    private:
        string term;
        Course* courses[5][7];

};


#endif