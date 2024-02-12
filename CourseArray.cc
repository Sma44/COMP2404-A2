#include <iostream>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray()
{
  nextID = COURSE_ID;
  size = 0;
}

CourseArray::~CourseArray()
{
  for (int i=0; i<size; ++i) {
    delete elements[i];
  }
}

void CourseArray::add(Course* d)
{
  if (size >= MAX_ARR){ return; }

  bool flag = true;

  if (size == 0){
    elements[0] = d;
    elements[0]->setId(nextID);
    nextID++;
    size++;
    return;
  }

  for (int i = 0; i < size; i++){
    if(elements[i]->lessThan(d)){
      for (int j = size; j > i; j--){
        elements[j] = elements[j-1];
      }
      elements[i] = d;
      elements[i]->setId(nextID);
      flag = false;
      break;
    }
  }

  if (!flag){
    elements[size] = d;
    elements[size]->setId(nextID);
  }
  nextID++;
  size++;
  
}

void CourseArray::print(string s)
{
  cout << endl << endl << "COURSES:" << endl;

  for (int i=0; i<size; ++i) {
    if(elements[i]->getTerm() == s){
      elements[i]->print();
    }
  }
}

bool CourseArray::find(int id, Course** c){

  for (int i = 0; i < size; i++){
    if(elements[i]->getId() == id){
      *c = elements[i];
      return true;
    }
  }

  *c = nullptr;
  return false;

}