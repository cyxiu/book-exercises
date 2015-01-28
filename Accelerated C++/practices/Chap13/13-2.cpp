#include <stdexcept>
#include <iostream>

#include "Student_info.h"

using namespace std;

int main() {
  Core* p1 = new Core;
  Core* p2 = new Grad;
  Core s1;
  Grad s2;

  cout << "p1" << endl;
  try {
    p1->grade();
  }
  catch (domain_error e) { }
  //core grade
  p1->name();
  //core name

  cout << "p2" << endl;
  try {
    p2->grade();
  //grad grade
  //core grade
  }
  catch (domain_error e) { }
  p2->name();
  //core name

  cout << "s1" << endl;
  try {
    s1.grade();
  //core grade
  }
  catch (domain_error e) { }
  s1.name();
  //core name

  cout << "s2" << endl;
  try {
    s2.grade();
  //grad grade
  //core grade
  }
  catch (domain_error e) { }
  s2.name();
  //core name

  return 0;
}
