#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <iostream>
#include <string>

//#include "Student_info.cpp"

struct Student_info {
    std::string name;
    double midterm, finals;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
