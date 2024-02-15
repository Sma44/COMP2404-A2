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
  hours = (h >= 0 && h < 24) ? h : 0;
  minutes = (m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins()
{
  return (hours * 60 + minutes);
}

void Time::print()
{
  cout << right << setfill('0') << setw(2) << hours << ":"
       << right << setfill('0') << setw(2) << minutes;
}

/// @brief computes the timeslot corresponding to this
/// @param slot return for timeslot
/// @return , true if successful, else false
bool Time::computeSlot(TimeSlotType &slot){
  bool ret = true;
  switch (hours){
  case 8:
    slot = SLOT_0830;
    break;
  case 10:
    slot = SLOT_1000;
    break;
  case 11:
    slot = SLOT_1130;
    break;
  case 13:
    slot = SLOT_1300;
    break;
  case 14:
    slot = SLOT_1430;
    break;
  case 16:
    slot = SLOT_1600;
    break;
  case 18:
    slot = SLOT_1800;
    break;
  default:
    slot = BAD_TIME_SLOT;
    cout << endl << "error in the time compute" << endl;
    ret = false;
    break;
  }
  return ret;
}

/// @brief sets this to the given timeslot
/// @param slot , the timeslot ot compute for
/// @return ,true if successful, else false
bool Time::setFromSlot(TimeSlotType slot){
  bool ret = true;
  switch (slot){
  case SLOT_0830:
    set(8, 30);
    break;
  case SLOT_1000:
    set(10, 0);
    break;
  case SLOT_1130:
    set(11, 30);
    break;
  case SLOT_1300:
    set(13, 0);
    break;
  case SLOT_1430:
    set(13, 0);
    break;
  case SLOT_1600:
    set(13, 0);
    break;
  case SLOT_1800:
    set(13, 0);
    break;
  case BAD_TIME_SLOT:
    set(13, 0);
    cout << endl << "error in the timeslot set" << endl;
    ret = false;
    break;
  }
  return ret;
}