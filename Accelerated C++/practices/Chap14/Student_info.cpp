#include <stdexcept>

#include "Student_info.h"

using namespace std;

//Student_info

std::istream& Student_info::read(std::istream& is) {
    char ch;
    is >> ch;
    if (is) {
        if (ch == 'U') {
            cp = new Core(is);
        } else if (ch == 'G') {
            cp = new Grad(is);
        } else if (ch == 'P') {
            cp = new Pf(is);
        } else {
            //cout << '-' << ch << '-' << ch << '-' <<  ch << endl;
            throw runtime_error("invalid student type");
        }
    } else {
        //cp = Ref_handle<Core>();
        cp = Ptr<Core>();
    }
    return is;
}

/*
Student_info::Student_info(const Student_info& s): cp(0) {
    std::cerr << "Student_info::Student_info(const S_i)" << std::endl;
    if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
    std::cerr << "Student_info::operator=(const S_i)" << std::endl;
    if (&s != this) {
        //cout << "self assignment!" << endl;
    //}
        delete cp;
        //cout << "cloning" << endl;
        //Core* temp = cp->clone();
        //Core* temp2 = s.cp->clone();
        //cout << bool(cp) << endl;
        //cout << bool(s.cp) << endl;
        if (s.cp) {
            cp = s.cp->clone();
        } else {
            cp = 0;
        }
    }
    return *this;
}
*/

//Core

double Core::grade() const { 
    //std::cerr << "Core::grade" << std::endl;
    return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in) {
    in >> n >> midterm >> final;
    return in;
}

std::istream& Core::read(std::istream& in) {
    read_common(in);
    read_hw(in, homework);
    return in;
}


//Grad

std::istream& Grad::read(std::istream& in) {
    read_common(in);
    in >> thesis;
    read_hw(in, homework);
    return in;
}

double Grad::grade() const {
    //std::cerr << "Grad::grade" << std::endl;
    return min(Core::grade(), thesis);
}

/*

*/
bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2) {
    return c1.grade() < c2.grade();
}



















//old ones
// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x) hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

