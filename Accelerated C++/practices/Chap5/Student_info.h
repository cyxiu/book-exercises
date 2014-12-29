#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <list>
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
std::ostream& disp_v(std::ostream&, std::vector<Student_info>);
std::ostream& disp_l(std::ostream&, std::list<Student_info>);

#endif
