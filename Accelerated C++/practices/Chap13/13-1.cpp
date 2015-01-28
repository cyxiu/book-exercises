#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

int main() {
    Student_info s1;
    /*
    S_i::S_i()
    */
    s1.read(cin);
    /*
    Core::Core()
    Grad::Grad(istream)
    */


    //for 13-9
    /*
    Student_info& s1copy = s1;

    cout <<s1.name() << endl;
    cout <<s1copy.name() << endl;
    cout << "now s1=s1copy" << endl;

    s1 = s1copy;
    cout <<s1.name() << endl;
    */


    Student_info s2;
    /*
    S_i::S_i()
    */
    s2.read(cin);
    /*
    Core::Core(istream)
    */

    Student_info s3 = s1;
    //Si(const Si)
    //Grad::clone

    s3 = s2;
    //Si oper=
    //~Core
    //Core::clone

    Student_info s4(cin);
    //Si(istream)
    //Core()
    //Grad::Grad(istream)
    
    //.....
    //~S-i
    //~Core
    //~S-i
    //~Core
    cout <<s1.name() << endl;
    return 0;
    
    
}
