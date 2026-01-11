#include <iostream>
#include <cstring>
#include <iomanip>

#include "Node.h"
#include "Student.h"

using namespace std;

void add(Node*& current, Node* prev, Node*& data);
void print(Node* current);
void del(Node*& current, Node* prev, int id);
void avg(Node* current, float& sum, float& num);
void quit(Node*& current);

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

    cout << "\n";
    cout << "Enter Command: ";
    cin >> input;
    cout << "\n";

    char first[99] = "";
    char last[99] = "";
    int id = 0;
    float gpa = 0;

    if (strcmp(input, ADD) == 0) {
      
      cout << "Enter first name: ";
      cin >> first;

      cout << "Enter last name: ";
      cin >> last;

      cout << "Enter id: ";
      cin >> id;

      cout << "Enter gpa: ";
      cin >> gpa;
      
      Student* student = new Student(first, last, id, gpa);
      Node* node = new Node(student);
      Node* prev = NULL;

      add(head, prev, node);
      
    } else if (strcmp(input, PRINT) == 0) {
      print(head);
    } else if (strcmp(input, DEL) == 0) {
      cout << "Enter id: ";
      cin >> id;

      Node* prev = NULL;
      
      del(head, prev, id);
      
    } else if (strcmp(input, AVG) == 0) {
      float sum = 0;
      float n = 0;
      avg(head, sum, n);
    } else if (strcmp(input, QUIT) == 0) {
      run = false;
      quit(head);
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
    
    if ((id < currentId) && (prev == NULL)) { // Change head
      data->setNext(current);
      current = data;
    } else if (id < currentId) { // insert
      prev->setNext(data);
      data->setNext(current);
    } else if (current->getNext() == NULL) { // End insert
      current->setNext(data);
    } else {
      Node* next = current->getNext();
      add(next, current, data);
    }
  }
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

void avg(Node* current, float& sum, float& n) {
  if (current != NULL) {
    sum += current->getStudent()->getGpa();
    n += 1;
    if (current->getNext() != NULL) {
      Node* next = current->getNext();
      avg(next, sum, n);
    } else {
      cout << fixed << setprecision(2) << sum/n;
    }
  }
}

void quit(Node*& current) {
  if (current != NULL) {
    if (current->getNext() != NULL) {
      Node* next = current->getNext();
      quit(next);
    }
    delete current;
    current = NULL;
  }
}
