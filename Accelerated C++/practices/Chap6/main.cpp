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
#include "grade5.h"
#include "Student_info.h"
#include "fail.h"
#include "extract.h"

using namespace std;

int main(){
    typedef vector<Student_info> typ;
    typ students;
    typ did, didnt;
    Student_info record;
    typedef string::size_type str_sz;
    str_sz maxlen = 0;

    //put student records in a collection
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);

        //new here
        if (did_all_hw(record)) {
            did.push_back(record);
        }
        else {
            didnt.push_back(record);
        }
    }

    if (did.empty()) {
        cout << "No student did all hw" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "all student did all hw" << endl;
        return 1;
    }

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

    write_analysis(cout, "median", hw_analysis, grade_aux, did, didnt);
    write_analysis(cout, "average", hw_analysis, average_grade, did, didnt);
    write_analysis(cout, "median turned in", hw_analysis, optimistic_median, did, didnt);

    typ fails = extract_one(students);
    //typ fails = extract_two(students);
    disp(cout, fails);
    cout<<endl;
    disp(cout, students);


    return 0;
}
