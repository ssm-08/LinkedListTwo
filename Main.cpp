#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*& current, Node* prev, Node*& data);
void print(Node*& head);
void del(Node*& head);
void avg(Node*& head);
bool quit(Node*& head);

int main() {
  bool run = true;
  Node* head = NULL;

  char input[99] = "";
  
  const char* ADD = "ADD";
  const char* PRINT = "PRINT";
  const char* DEL = "DELETE";
  const char* AVG = "AVERAGE";
  const char* QUIT = "QUIT";
  
  while (run == true) {
    cout << "Enter Command: ";
    cin.getline(input, 99);

    if (strcmp(input, ADD) == 0) {
      char first[99] = "";
      char last[99] = "";
      char id[99] = "";
      char gpa[99] = "";
      
      cout << "Enter first name: ";
      cin.getline(first, 99);

      cout << "Enter last name: ";
      cin.getline(last, 99);

      cout << "Enter id: ";
      cin.getline(id, 99);

      cout << "Enter gpa: ";
      cin.getline(gpa, 99);

      cout << "vars";
      
      Student* student = new Student(first, last, atoi(id), atoi(gpa));
      Node* node = new Node(student);
      Node* prev = NULL;

      cout << "adding" << endl;
      add(head, prev, node);
      
    } else if (strcmp(input, PRINT) == 0) {
      print(head);
    } else if (strcmp(input, DEL) == 0) {
    } else if (strcmp(input, AVG) == 0) {
    } else if (strcmp(input, QUIT) == 0) {
    }
  }  
}

void add(Node*& current, Node* prev, Node*& data) {

  int currentId = 0;
  int id = 0;
  
  if (current == NULL) {
    current = data; 
  } else {
    currentId = current->getStudent()->getId();
    id = data->getStudent()->getId();

    cout << currentId << " " << id;
    
    if ((id < currentId) && (prev == NULL)) { // Change head
      cout << "new";
      data->setNext(current);
      current = data;
    } else if (id < currentId) { // insert
      cout << "insert";
      prev->setNext(data);
      data->setNext(current);
    } else if (current->getNext() == NULL) { // End insert
      cout << "end";
      current->setNext(data);
    } else {
      cout << "recurse";
      Node* next = current->getNext();
      add(next, current, data);
    }
  }

  cout << "done";
}

void print(Node*& head) {
  if (head != NULL) {
    head->getStudent()->getDisplay();
    if (head->getNext() != NULL) {
      Node* next = head->getNext();
      print(next);
    }
  }
}
