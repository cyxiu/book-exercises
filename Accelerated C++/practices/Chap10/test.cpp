#include "median.h"
#include "letter_grade.h"

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    const int a[] = {1,3,2};
    cout << *a << endl;
    cout << median1<int>(a, a+3) << endl;
    const vector<int> b = {1,99,20};
    cout << median1<int>(b.begin(), b.end()) << endl;

    int x = 5;
    int* p = &x;
    cout << x << endl;
    (*p)++;
    cout << x << endl;


    cout << letter_grade(99) << endl << letter_grade(85) << endl << letter_grade(30) << endl;

    //test cout << char*
    char c[] = "Hello";
    char* d = c;
    cout << c[5] <<endl;
    cout << c[4] <<endl;
    cout << c <<endl;
    cout << d <<endl;

    if (argc > 1) {
        cout << argv[0] << endl;
        cout << argv[1];

        for (int i =2; i<argc; i++) {
            cout << " " << argv[i];
        }
        cout << endl;
    }

    return 0;
}
