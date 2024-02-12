#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "Course.h"
#include "defs.h"


class CourseArray
{
  public:
    CourseArray();
    ~CourseArray();
    void add(Course*);
    void print(string);
    bool find(int, Course**);

  private:
    Course* elements[MAX_ARR];
    int   size;
    int nextID;
};

#endif

