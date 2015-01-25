#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    double grade() const;
    std::istream& read(std::istream&);
    //changed for 9-2
    //std::string name() { return n; }
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

    //constructors
    Student_info();
    Student_info(std::istream&);

private:
    std::string n;
    double midterm, finals;
    std::vector<double> homework;

};

bool compare(const Student_info&, const Student_info&);
//changed for 9-2
//bool compare(Student_info&, Student_info&);

#endif

