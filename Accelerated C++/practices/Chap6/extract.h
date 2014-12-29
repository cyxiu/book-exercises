#ifndef GUARD_extract_h
#define GUARD_extract_h
#include <vector>
#include <list>
#include "Student_info.h"
#include "fail.h"

bool pgrade(const Student_info&);
std::vector<Student_info> extract_two(std::vector<Student_info>&);
std::vector<Student_info> extract_one(std::vector<Student_info>&);

#endif
