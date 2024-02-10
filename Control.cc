#include <iostream>
using namespace std;
#include <string>


void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

