#include <iostream>
#include <vector>
#include "8-4.h"

using namespace std;

int main() {
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    book_reverse(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
