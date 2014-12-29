#ifndef GUARD_FAIL_H
#define GUARD_FAIL_H

#include <vector>
#include <list>
#include "Student_info.h"
#include "grade5.h"

bool fgrade(const Student_info& stu);
std::vector<Student_info> fails(std::vector<Student_info>& students);
//std::list<Student_info> fails(std::list<Student_info>& students);
int passfirst(std::vector<Student_info>&);
#endif
