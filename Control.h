#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <iomanip>

#include "defs.h"
#include "School.h"
#include "View.h"
#include "Schedule.h"
#include <string.h>
using namespace std;


class Control
{
  public:
    Control(string="N/A");
    ~Control();
    void launch();
    
  private:
    void initCourses(School*);
    bool addSched(Schedule*);
    bool findSched(string,Schedule**);
   
    School* school;
    View view;
    Schedule* scheds[MAX_ARR];
    int numScheds;

};

#endif
