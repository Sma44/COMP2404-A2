#include <iostream>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray(){
  nextID = COURSE_ID;
  size = 0;
}

/// @brief deletes each course in the array
CourseArray::~CourseArray(){
  for (int i=0; i<size; i++) {
    delete elements[i];
  }
}

/// @brief adds a given course to the array in ascending order
/// @param d , the course to add
void CourseArray::add(Course* d){
  if (size == MAX_ARR){ return; }

  bool flag = false;

  if (size == 0){
    cout << "entered first element" << endl;
    elements[0] = d;
    elements[0]->setId(nextID);
    nextID++;
    size++;
    return;
  }

  for (int i = 0; i < size; i++){
    if(d->lessThan(elements[i])){
      for (int j = size; j > i; j--){
        elements[j] = elements[j-1];
      }
      elements[i] = d;
      elements[i]->setId(nextID);
      flag = true;
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

/// @brief prints each course in array
/// @param term , the given term to match
void CourseArray::print(string term){
  cout << endl << endl << "COURSES:" << endl;

  for (int i=0; i<size; ++i) {
    if(elements[i]->getTerm() == term){
      elements[i]->print();
    }
  }
}

/// @brief finds a given course with the id
/// @param id , id to match with course
/// @param c , returns the course found
/// @return ,true if found, else false
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