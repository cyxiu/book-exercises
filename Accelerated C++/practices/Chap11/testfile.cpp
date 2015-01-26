#include <vector>
#include <iostream>

using namespace std;

vector<int>& id(vector<int>& a) {
    return a;
}

int main() {
    vector<int> a(10,9);
    vector<int> b;
    cout << a[0] << a[1] << endl;
    vector<int>& c = (b = a);
    cout << b[0] << b[1] << endl;
    cout << c[0] << c[1] << endl;
    b[0] = 4;
    cout << b[0] << b[1] << endl;
    cout << c[0] << c[1] << endl;

    vector<int> res = id(b);
    vector<int>& resref = id(b);
    cout << res[0] << res[1] << endl;
    cout << resref[0] << resref[1] << endl;
    b[1] = 8;
    cout << res[0] << res[1] << endl;
    cout << resref[0] << resref[1] << endl;
    cout << b[0] << b[1] << endl;

    return 1;
}
