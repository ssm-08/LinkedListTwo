#include <iostream>
#include <cstring>

#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*& current, Node* prev, Node*& data);
void print(Node* current);
void del(Node*& current, Node* prev, int id);
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
    cin >> input;

    char first[99] = "";
    char last[99] = "";
    int id = 0;
    int gpa = 0;

    if (strcmp(input, ADD) == 0) {
      
      cout << "Enter first name: ";
      cin >> first;

      cout << "Enter last name: ";
      cin >> last;

      cout << "Enter id: ";
      cin >> id;

      cout << "Enter gpa: ";
      cin >> gpa;

      cout << "vars";
      
      Student* student = new Student(first, last, id, gpa);
      Node* node = new Node(student);
      Node* prev = NULL;

      cout << "adding" << endl;
      add(head, prev, node);
      
    } else if (strcmp(input, PRINT) == 0) {
      print(head);
    } else if (strcmp(input, DEL) == 0) {
      cout << "Enter id: ";
      cin >> id;

      Node* prev = NULL;
      
      del(head, prev, id);
      
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

void print(Node* current) {
  if (current != NULL) {
    current->getStudent()->getDisplay();
    if (current->getNext() != NULL) {
      Node* next = current->getNext();
      print(next);
    }
  }
}

void del(Node*& current, Node* prev, int id) {
  cout << "del";
  if (current != NULL) {
    if (current->getStudent()->getId() == id) {
      prev->setNext(current->getNext());
      delete current;
      current = NULL;
    } else if (current->getNext() != NULL) {
      Node* next = current->getNext();
      del(next, current, id);
    }
  }
}
