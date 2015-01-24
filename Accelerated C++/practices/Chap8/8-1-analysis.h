#ifndef GUARD_81analysis
#define GUARD_81analysis

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "median.h"
#include "../../chapter04/Student_info.h"

bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double average_grade(const Student_info& s);
double optimistic_median(const Student_info& s);

template <class Func> double analysis(const std::vector<Student_info>& students, Func grading_function) {
    std::vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grading_function);
    return median(grades);
}

template <class Func> void write_analysis(std::ostream& out, const std::string& name, Func grading_function, const std::vector<Student_info>& did, const std::vector<Student_info>& didnt) {
    out << name << "did = " << analysis(did, grading_function) << ", didnt" << analysis(didnt, grading_function) << std::endl;
}



#endif
