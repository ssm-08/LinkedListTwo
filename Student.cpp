#include "Student.h"

Student::Student(char f[99], char l[99], int i, int g) {
  strcpy(firstName, f);
  strcpy(lastName, l);
  id = i;
  gpa = g;
}

Student::~Student() {
  delete[] firstName;
  firstName = NULL;

  delete[] lastName;
  lastName = NULL;
  id = 0;
  gpa = 0;
}

void Student::getDisplay() {
  cout << "\n";
  cout << firstName;
  cout << " ";
  cout << lastName;
  cout << ", ";
  cout << id;
  cout << ", ";
  cout << gpa;
}

int Student::getId() {
  return id;
}

int Student::getGpa() {
  return gpa;
}
