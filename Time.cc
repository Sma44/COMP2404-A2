#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins()
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout << right << setfill('0')<<setw(2)<<hours<<":"
       << right << setfill('0')<<setw(2)<<minutes;
}

