#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

int main() {
    //testing for a bugging question
    Student_info si;
    /*
    S_i()
    */
    si.read(cin);
    /*
    Core(istream)
    */

    cout << "about to new/assignment" << endl;

    si = new Core(cin);
    /*  guessed output
    Core(istream)   generate a new Core() return a Core*
    S_i(Core*)      automatic conversion because S_i has a constructor taking Core*
    S_i::oper=(const S_i&)  starting the assignment
    ~Core()         delete the old Core object
    Core::clone()   cloning
    ~S_i            destroy the automatically converted S_i object
    ~Core           destroy the Core object in it
    */

    /*actual output
    Student_info::Student_info()
    Core::Core(std::istream& is)
        about to new/assignment
    Core::Core(std::istream& is)
    Student_info::Student_info(Core*)
    Student_info::operator=(const S_i)
    Core::~Core()
    Core::clone()
    Student_info::~Student_info()
    Core::~Core()
        about to exit
    Student_info::~Student_info()
    Core::~Core()
    */

    cout << "about to exit" << endl;
    
    return 0;
    
    
}

