#include <iostream>
#include <cstring>

#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*& current, Node*& prev, Node*& data);
void print(Node*& head);
void del(Node*& head);
void avg(Node*& head);
bool quit(Node*& head);

int main() {
  bool run = true;
  Node* head = NULL;

  char input[99];

  const char* ADD = "ADD";
  const char* PRINT = "PRINT";
  const char* DEL = "DELETE";
  const char* AVG = "AVERAGE";
  const char* QUIT = "QUIT";
  
  while (run == true) {
    cout << "Enter Command: ";
    cin >> input;

    if (strcmp(input, ADD) == 0) {
      char first[99];
      char last[99];
      int id;
      int gpa;

      cout << "Enter first name: ";
      cin >> first;

      cout << "Enter last name: ";
      cin >> last;

      cout << "Enter id: ";
      cin >> id;

      cout << "Enter gpa: ";
      cin >> gpa;

      Student* student = new Student(first, last, id, gpa);
      
      
    } else if (strcmp(input, PRINT) == 0) {
    } else if (strcmp(input, DEL) == 0) {
    } else if (strcmp(input, AVG) == 0) {
    } else if (strcmp(input, QUIT) == 0) {
    }
  }  
}

void add(Node*& current, Node*& prev, Node*& data) {
  
  int currentId = current->getStudent()->getId();
  int id = data->getStudent()->getId();;

  
  if (current == NULL) {
    // Create first data
  } else if ((id < currentId) && (prev == NULL)) {
    // Set new head
  } else if (current->getNext() == NULL) {
    // Set last node
  } else if (id << currentId) {
    // Insert
  } else {
    Node* next = current->getNext();
    add(next, current, data);
  }
}
