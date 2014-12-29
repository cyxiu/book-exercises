#include "fail.h"

using namespace std;

bool fgrade(const Student_info& stu) {
    return grade(stu) < 60;
}

typedef vector<Student_info> typ;
//typedef list<Student_info> typ;

typ fails(typ& students) {
    typ fails;
    typ::iterator iter = students.begin();
    //WRONG to use for
    //for (typ::iterator iter = students.begin(); iter != students.end(); ++iter) {
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fails.push_back(*iter);
            iter = students.erase(iter);
        }
        else {
            iter++;
        }
    }
    return fails;
}

int passfirst(typ& students) {
    typ::size_type i = 0;
    typ::size_type j = 0;
    //invariant: [0,i) are pass students, [i, j) are failed students
    while (j != students.size()) {
        //invariant: [i, j) are failed students
        while (j != students.size() && !fgrade(students[j])) {
            j++;
        }
        if (j != students.size()) {
            //swap i and j
            Student_info temp = students[i];
            students[i] = students[j];
            students[j] = temp;
            i++;
            j++;
        }
    }
    return 0;
}
