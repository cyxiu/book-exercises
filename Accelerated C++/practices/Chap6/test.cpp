#include <iostream>
using namespace std;
int main() {
    int a=0, b=0, c=5;
    cout<< a << endl;
    cout<< (a = 5) << endl;
    cout<< ((a = 5) == b) << endl;
    cout<< ((a = 5) == c) << endl;
    return 0;
}
