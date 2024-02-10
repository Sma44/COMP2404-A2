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

bool Time::computeSlot(TimeSlotType& slot){

  switch(hours){
    case 8:
      slot=SLOT_0830;
      return true;
    case 10:
      slot=SLOT_1000;
      return true;
    case 11:
      slot=SLOT_1130;
      return true;
    case 13:
      slot=SLOT_1300;
      return true;
    case 14:
      slot=SLOT_1430;
      return true;
    case 16:
      SLOT_1600;
      return true;
    case 18:
      slot=SLOT_1800;
      return true;
    default:
      slot=BAD_TIME_SLOT;
      cout << endl << "error in the time" << endl;
      break;
  }

  return false;
}

bool Time::setFromSlot(TimeSlotType slot){

    switch(slot){
    case SLOT_0830:
      set(8,30);
      return true;
    case SLOT_1000:
      set(10,0);
      return true;
    case SLOT_1130:
      set(11,30);
      return true;
    case SLOT_1300:
      set(13,0);
      return true;
    case SLOT_1430:
      set(13,0);
      return true;
    case SLOT_1600:
      set(13,0);
      return true;
    case SLOT_1800:
      set(13,0);
      return true;
    case BAD_TIME_SLOT:
      set(13,0);
      return false;
  }

  return false;
}