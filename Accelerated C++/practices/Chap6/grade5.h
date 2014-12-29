#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <iostream>
#include <string>
#include "Student_info.h"

double grade(const Student_info&);
double grade(const std::vector<double>&);
double grade(double, double, double);

#endif
