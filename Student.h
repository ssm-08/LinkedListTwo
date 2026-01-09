#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {
 public:
  // Constructor and Destructor
  Student(char f[99], char l[99], int i, int g);
  ~Student();

  // Print Student name & grade
  void getDisplay();

  int getId();
  int getGpa();
  
 private:
  char* firstName;
  char* lastName;
  int id = 0;
  int gpa = 0;
};

#endif
