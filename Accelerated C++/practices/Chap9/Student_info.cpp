#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

using namespace std;

Student_info::Student_info(): midterm(0), finals(0) { }
Student_info::Student_info(std::istream& is) { read(is); }

istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

istream& Student_info::read(std::istream& in) {
    in >> n >> midterm >> finals;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, finals, homework);
}

bool compare(const Student_info& x, const Student_info& y) {
//changed for 9-2
//bool compare(Student_info& x, Student_info& y) {
    return x.name() < y.name();
}


int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store the data
  while (record.read(cin)) {                           // changed
    maxlen = max(maxlen, record.name().size());      // changed
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0;
       i != students.size(); ++i) {
    cout << students[i].name()   // this and the next line changed
	 << string(maxlen + 1 - students[i].name().size(), ' ');
    try {
      double final_grade = students[i].grade();   // changed
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
	   << setprecision(prec) << endl;
    } catch (domain_error e) {
      cout << e.what() << endl;
    }
  }

  return 0;
}

