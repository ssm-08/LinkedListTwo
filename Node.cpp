// this is Node. cpp

#include <iostream>
#include <cstring>
using namespace std;

#include "Node.h"

//construscor
Node::Node(Student* newStudent){
  student = newStudent;
  next = NULL;
}

// destructor
Node::~Node(){
}

// get next node
Node* Node::getNext(){
  return next;
}

// get student
Student* Node::getStudent(){
  return student;
}

//set next node
void Node::setNext(Node* newNext){
  next = newNext;
}
