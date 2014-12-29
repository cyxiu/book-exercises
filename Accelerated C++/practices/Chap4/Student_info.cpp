//#include <vector>
//#include <iostream>
//#include <string>

#include "Student_info.h"

using namespace std;

bool compare(const Student_info& stu1, const Student_info& stu2) {
    return stu1.name < stu2.name;
}

std::istream& read(std::istream& is, Student_info& stu) {
    //this doesn't work as expected  
    //cout << "name? ";
    //is >> stu.name;
    //cout << "midterm? ";
    //is >> stu.midterm;
    //cout << "final? ";
    //is >> stu.finals;
    is >> stu.name >> stu.midterm >> stu.finals;
    read_hw(is, stu.homework);
    return is;
}

std::istream& read_hw(std::istream& is, vector<double>& hw) {
    if (is) {
        hw.clear();
        double score;
        while (is >> score) {
            hw.push_back(score);
        }
        is.clear();
    }
    return is;
}
