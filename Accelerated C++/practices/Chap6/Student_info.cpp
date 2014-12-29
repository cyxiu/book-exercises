//#include <vector>
//#include <iostream>
//#include <string>

#include "Student_info.h"

using namespace std;
typedef Student_info si;

bool compare(const si& stu1, const si& stu2) {
    return stu1.name < stu2.name;
}

istream& read(istream& is, si& stu) {
    //this doesn't work as expected  
    //cout << "name? ";
    //is >> stu.name;
    //cout << "midterm? ";
    //is >> stu.midterm;
    //cout << "final? ";
    //is >> stu.finals;
    is >> stu.name;
    if (stu.name == "p") {
        stu.midterm = 100;
        stu.finals = 90;
        stu.homework = vector<double>(5, 100);
    }
    else if (stu.name == "f") {
        stu.midterm = 20;
        stu.finals = 30;
        stu.homework = vector<double>(5, 5);
    }
    else if (stu.name == "p0") {
        stu.midterm = 100;
        stu.finals = 90;
        stu.homework = vector<double>(5, 100);
        stu.homework.end()[-1] = 0;
    }
    else if (stu.name == "f0") {
        stu.midterm = 20;
        stu.finals = 30;
        stu.homework = vector<double>(5, 5);
        stu.homework.end()[-1] = 0;
    }
    else {
        is >> stu.midterm >> stu.finals;
        read_hw(is, stu.homework);
    }
    return is;
}

istream& read_hw(istream& is, vector<double>& hw) {
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

ostream& disp(ostream& o, vector<si> v) {
    for (vector<si>::const_iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->name << " " << iter->midterm << " " << iter->finals << endl;
    }
    return o;
}

ostream& disp(ostream& o, list<si> l) {
    for (list<si>::const_iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << iter->name << " " << iter->midterm << " " << iter->finals << endl;
    }
    return o;
}
