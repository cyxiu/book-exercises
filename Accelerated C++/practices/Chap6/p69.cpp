#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <string>

using namespace std;

typedef vector<string> vs;

string conc(vs v) {
    string ret = "00";
    ret = accumulate(v.begin(), v.end(), ret);
    return ret;
}

int main() {
    vs v = {"a ", "b ", "c "};
    v = vs(10, string("Hala Madrid! "));
    cout << conc(v) << endl;
    return 0;
}
