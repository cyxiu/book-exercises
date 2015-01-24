#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>

#include "median.h"

using namespace std;

int main() {
    vector<int> vi;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vi));
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " , "));
    cout << median(vi) << endl;
    return 0;
}
