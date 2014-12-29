#include <string>
#include <iostream>


using namespace std;

int main() {
    string s0 = "abc";
    string s;
    string& sref = s;
    cout << sref << endl;       //out put empty
    sref = s0;      //this is copy!
    cout << sref << endl;       //abc
    sref[0] = 'f';
    cout << sref << endl;       //fbc
    cout << "s0 " << s0 << endl;    //still abc

    string s1 = "xyz";
    string s2 = "nnn";
    string& sref1 = s1;         //this is reference
    cout << sref1 << endl;       //xyz
    sref[0] = 'f';
    cout << "sref1 " << sref1 << endl;       //fbc
    cout << "s1 " << s1 << endl;    //fbc
    sref1 = s2;
    cout << "sref1 " << sref1 << endl;       //nnn
    cout << "s1 " << s1 << endl;    //nnn
    return 0;
}
