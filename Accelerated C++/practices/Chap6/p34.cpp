#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>

using namespace::std;
typedef vector<int>::iterator iter;

int p34() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());
    for (iter i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}

int p35a(){
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));
    for (iter i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}

int p35b(){
    vector<int> u(10, 100);
    vector<int> v(11);
    copy(u.begin(), u.end(), v.begin());
    for (iter i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}


int main(){
    p35b();
    return 0;
}
