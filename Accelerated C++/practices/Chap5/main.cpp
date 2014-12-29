#include <ios>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
//#include <typeinfo>

#include "grade.h"
#include "Student_info.h"
#include "fail.h"

using namespace std;

int main(){
    typedef vector<Student_info> typ;
    //vector<Student_info> studentsv;
    typ students;
    Student_info record;
    typedef string::size_type str_sz;
    //typedef vector<Student_info>::size_type vec_sz;
    //typedef list<Student_info>::size_type li_sz;
    str_sz maxlen = 0;

    //put student records in a collection
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    //for a vector
    /*
    sort(studentsv.begin(), studentsv.end(), compare);
    for (vec_sz i = 0; i < studentsv.size(); i++){
        cout<< studentsv[i].name << string(maxlen + 1 - studentsv[i].name.size(), ' ');

        try {
            double final_grade = grade(studentsv[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    */

    for (typ::iterator iter = students.begin(); iter != students.end(); iter++){
        cout<< iter->name << string(maxlen + 1 - iter->name.size(), ' ');

        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    typ students2 = students;
    cout << "fails v starts" << endl;
    typ failstu = fails(students);
    disp_v(cout, failstu);
    cout << "fails v ends" << endl;
    cout << "passfirst starts" << endl;
    passfirst(students2);
    disp_v(cout, students2);
    cout << "passfirst ends" << endl;

    ///can insert from a list to a vector
    /*
    vector<Student_info> failsv = fails_v(studentsv);
    list<Student_info> failsl = fails_l(studentsl);
    cout << "failsv" << endl;
    disp_v(cout, failsv);
    cout << "failsl" << endl;
    disp_l(cout, failsl);
    failsl.insert(failsl.begin(), failsv.begin(), failsv.end());
    cout << "failsl" << endl;
    disp_l(cout, failsl);
    */
    return 0;
}
