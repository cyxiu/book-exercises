#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "extract.h"

using namespace std;
typedef Student_info si;

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

vector<si> extract_two(vector<si>& students) {
    vector<si> fail;
    remove_copy_if(students.begin(), students.end(), (back_inserter(fail)), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    return fail;
}

vector<si> extract_one(vector<si>& students) {
    vector<si>::iterator iter;
    iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<si> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}

