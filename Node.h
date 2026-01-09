/* this is Node.h
   Linked list

   Lihi Gavrielov
   12/18/25
 */


#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

class Node{
 private:
  // pointer to a student object
  Student* student;
  // pointer to next Node
  Node* next;

 public:
  //Constructor
  Node(Student* newStudent);

  //destructor
  ~Node();

  // get next Node pointer
  Node* getNext();

  //get student pointer
  Student* getStudent();

  //set the next Node pointer
  void setNext(Node* newNext);
};
#endif
