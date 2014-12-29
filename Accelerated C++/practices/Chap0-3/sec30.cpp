#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cout << "Final and "
            "midterm score please";
    double midterm, fin;
    cin >> midterm >> fin;

    cout << "home work grades please, followed by end-of-file";
    vector<double> homework;
    double x;
    while (cin >> x) {
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "0 homework" << endl;
        return 1;
    }


    sort(homework.begin(), homework.end());

    vec_sz mid = size/2;
    double median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];
    cout << endl << "median is: " << median << endl;

    streamsize prec = cout.precision();
    cout << endl << "total: " << setprecision(4) << 0.2 * midterm + 0.4 * fin + 0.4 * median << setprecision(prec) << endl;
    return 0;
}
