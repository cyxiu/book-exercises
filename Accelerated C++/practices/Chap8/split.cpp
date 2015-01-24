#include <iostream>

#include "split.h"

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        split(s, ostream_iterator<string>(cout, "\n"));
    }

    return 0;
}
