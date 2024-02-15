#ifndef TIME_H
#define TIME_H

#include "defs.h"

class Time
{
public:
  Time(int = 0, int = 0);
  bool computeSlot(TimeSlotType &);
  bool setFromSlot(TimeSlotType);
  void print();

private:
  int hours;
  int minutes;
  void set(int, int);
  int convertToMins();
};

#endif
