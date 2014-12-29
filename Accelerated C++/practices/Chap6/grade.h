#ifndef GUARD_grade_6_h
#define GUARD_grade_6_h

#include <vector>
#include <iostream>
#include <string>

#include "Student_info.h"
#include "grade5.h"

bool did_all_hw(const Student_info&);

double grade_aux(const Student_info&);

double average(const std::vector<double>&);

double average_grade(const Student_info&);

double optimistic_median(const Student_info&);

double hw_analysis(const std::vector<Student_info>&, double(const Student_info&));

void write_analysis(std::ostream&, const std::string&, double(const std::vector<Student_info>&, double(const Student_info&)), double(const Student_info&), const std::vector<Student_info>&, const std::vector<Student_info>&);

#endif
