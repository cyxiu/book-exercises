#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

#include "grade5.h"
#include "Student_info.h"
#include "fail.h"
#include "median.h"
#include "grade.h"

using namespace std;
typedef Student_info si;

bool did_all_hw(const si& s) {
    return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

double grade_aux(const si& s) {
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.midterm, s.finals, 0);
    }
}

double average(const vector<double>& v){
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const si& s) {
    return grade(s.midterm, s.finals, average(s.homework));
}

double optimistic_median(const si& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty()) 
        return grade(s.midterm, s.finals, 0);
    else 
        return grade(s.midterm, s.finals, median(nonzero));
}


//merge three analyses into one
double hw_analysis(const vector<si>& students, double grade_one(const si&)) {
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_one);
    return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<si>&, double(const si&)), double grade_one(const si&), const vector<si>& did, const vector<si>& didnt) {
    out << name << ": median(did) = " << analysis(did, grade_one) <<
                   ": median(didnt) = " << analysis(didnt, grade_one) << endl;
}

