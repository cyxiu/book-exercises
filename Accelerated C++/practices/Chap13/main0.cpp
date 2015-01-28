#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        //cout << record.name() << " loaded" << endl;
        students.push_back(record);
    }

    sort(students.begin(), students.end(), Student_info::compare);

    //cout << students.size() << endl;

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        cout << "valid? " << students[i].valid() << endl;
        cout << "fulfilled requirement? " << students[i].rqmt() << endl;

        try {
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    /*
    */
    //Grad g;
    return 0;
}
