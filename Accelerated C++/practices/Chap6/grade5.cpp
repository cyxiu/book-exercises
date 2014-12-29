#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "grade5.h"
#include "Student_info.h"
#include "median.h"

using namespace std;

double grade(const Student_info& stu) {
    if (stu.homework.size() == 0) {
        throw domain_error("No homework input");
    }
    double hwgrade;
    hwgrade = grade(stu.homework);
    return grade(stu.midterm, stu.finals, hwgrade);

}

double grade(double mid, double f, double hwgrade) {
    return mid * 0.2 + f * 0.4 + hwgrade * 0.4;
}

double grade(const vector<double>& hw) {           //not a &
    try {
        return median(hw);
    }
    catch (domain_error e) {
        throw domain_error("no homework grade input");
    }

}
