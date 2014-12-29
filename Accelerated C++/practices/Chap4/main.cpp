#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

using namespace std;

int main(){
    vector<Student_info> students;
    Student_info record;
    typedef string::size_type str_sz;
    typedef vector<Student_info>::size_type vec_sz;
    //str_sz maxlen = 0;
    //long unsigned int maxlen = 0; this works because str_sz == long unsigned int in my implementation
    int maxlen = 0;


    while (read(cin, record)) {
        cout << record.name << " " << record.midterm << " " << record.finals << endl;
        //maxlen = max(maxlen, record.name.size());
        maxlen = max(maxlen, int(record.name.size()));
        //if (maxlen < record.name.size()) {
            //maxlen = record.name.size();
        //}
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vec_sz i = 0; i < students.size(); i++){
        cout<< students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
