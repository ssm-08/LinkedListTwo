#include "Student.h"

Student::Student(char f[99], char l[99], int i, float g) {
  strcpy(firstName, f);
  strcpy(lastName, l);
  id = i;
  gpa = g;
}

Student::~Student() {
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
  cout << fixed << setprecision(2) << gpa;
  cout << "\n";
}

int Student::getId() {
  return id;
}

float Student::getGpa() {
  return gpa;
}
