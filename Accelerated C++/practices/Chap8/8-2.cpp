#include <iostream>
#include <vector>
#include "8-2.h"

using namespace std;

int main() {
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cin.clear();
    string s;
    getline(cin,s);
    cout << s << endl;
    vector<int> w;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(w));
    cout << my_equal(v.begin(), v.end(), w.begin());
    return 0;
}
