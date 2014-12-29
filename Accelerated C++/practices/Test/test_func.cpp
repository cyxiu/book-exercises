#include <iostream>
using namespace std;



int foo1(const int k) {
    cout << "const int" << endl;
    //k = 11;
    return 0;
}

int foo2(int k) {
    cout << "int" << endl;
    k = 22;
    return 0;
}

int foo3(int& k) {
    cout << "int&" << endl;
    k = 33;
    return 0;
}

int foo4(const int& k) {
    cout << "const int&" << endl;
    //k = 44;
    return 0;
}

//LEGAL overloaded!!
int bar(int& k) {
    cout << "bar int&" << endl;
    return 0;
}

int bar(int k) {
    cout << "bar int" << endl;
    return 0;
}

int main() {
    int i = 1;
    //ILLEGAL int& j = 2;
    //ILLEGAL int& j = i + 1;
    int& j = i;
    foo1(i);        // this works with int, int&, const int, const int&
    cout << i << endl;
    foo2(i);        
    cout << i << endl;
    foo3(i);       
    cout << i << endl;
    foo4(i);      
    cout << i << endl;
    /*
    foo1(j);        // this works with int, int&, const int, const int&
    foo2(j);        
    foo3(j);       
    foo4(j);      
    */
    //!!!!!!! WORKS with const int&, NOT int&
    foo1(9);         // works with int, const int, const int&; illegal with int&
    foo2(9);         
    //foo3(9);        //
    foo4(9);       

    //This is TRICKY business!!!
    cout << endl;
    //bar(j);
    bar(9);

}

