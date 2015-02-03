#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>

#include "grade.h"
#include "Ptr.h"

class Core {
    friend class Student_info;
    //friend class Handle<Core>;
    //friend class Ref_handle<Core>;
    friend class Ptr<Core>;
public:
    Core(): midterm(0), final(0) {
        //std::cerr << "Core::Core()" << std::endl;
    }
    Core(std::istream& is) { 
        //std::cerr << "Core::Core(std::istream& is)" << std::endl;
        read(is);
    }
    virtual ~Core() { 
        //std::cerr << "Core::~Core()" << std::endl;
    }

    std::string name() const { 
        //std::cerr << "Core::name()" << std::endl;
        return n; 
    }

    virtual bool valid() const {
        return !homework.empty();
    }

    virtual bool rqmt() const {
        return !homework.empty() && (std::find(homework.begin(), homework.end(), 0.0) == homework.end());
    }

    virtual std::istream& read(std::istream&);
    virtual double grade() const;

protected:
    virtual Core* clone() const { 
        //std::cerr << "Core::clone()" << std::endl;
        return new Core(*this); 
    }
    std::istream& read_common(std::istream&);
    double midterm, final;
    std::vector<double> homework;

private:
    std::string n;
};

class Grad: public Core {
public:
    Grad(): thesis(0) {
        //std::cerr << "Grad::Grad()" << std::endl;
    }
    Grad(std::istream& is) { 
        //std::cerr << "Grad::Grad(std::istream& is)" << std::endl;
        read(is); 
    }

    bool rqmt() const {
        return (Core::rqmt() && (thesis > 0.0));
    }

    double grade() const;
    std::istream& read(std::istream&);
protected:
    Grad* clone() const {
        //std::cerr << "Grad::clone()" << std::endl;
        return new Grad(*this);
    }
private:
    double thesis;
};

class Pf: public Core {
public:
    Pf() { }
    Pf(std::istream& is) { read(is); }

    bool rqmt() const { return true; }
    double grade() const {
        if (homework.empty()) {
            return (midterm + final)/2;
        } else {
            return Core::grade();
        }
    }
    std::istream& read(std::istream& is) {
        Core::read(is);
        return is;
    }
protected:
    Pf* clone() const {
        //std::cerr << "Pf::clone()" << std::endl;
        return new Pf(*this);
    }
};

std::istream& read_hw(std::istream&, std::vector<double>&);

/*
bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2) {
    return c1.grade() < c2.grade();
}
*/
bool compare(const Core&, const Core&);

bool compare_grades(const Core&, const Core&);

class Student_info {
public:
    Student_info() { 
        //std::cerr << "Student_info::Student_info()" << std::endl;
    }
    Student_info(std::istream& is) {
        //std::cerr << "Student_info::Student_info(istream)" << std::endl;
        read(is); 
    }
    /*
    Student_info(const Student_info&);
    Student_info& operator=(const Student_info&);
    ~Student_info() { 
        //std::cerr << "Student_info::~Student_info()" << std::endl;
        delete cp; 
    }
    //for a buggin test see copy_test.cpp
    Student_info(Core* c) {
        //std::cerr << "Student_info::Student_info(Core*)" << std::endl;
        cp = c;
    }
    */

    std::istream& read(std::istream&);

    std::string name() const {
        if (cp) {
            return cp->name();
        } else {
            throw std::runtime_error("uninitialized student");
        }
    }

    bool valid() const {
        if (cp == 0) {
            return false;
        } else {
            return cp->valid();
        }
    }

    bool rqmt() const {
        if (cp == 0) {
            return false;
        } else {
            return cp->rqmt();
        }
    }

    double grade() const {
        if (cp) {
            return cp->grade();
        } else {
            throw std::runtime_error("uninitialized student");
        }
    }

    static bool compare(const Student_info& s1, const Student_info& s2) {
        return s1.name() < s2.name();
    }

private:
    Ptr<Core> cp;
};

#endif
