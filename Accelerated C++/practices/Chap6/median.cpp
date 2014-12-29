#include <algorithm>
#include <stdexcept>
#include <vector>
//#include <iostream>

#include "median.h"

using namespace std;

double median(vector<double> vec) {

    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());
    //cout << vec.begin();

    vec_sz mid = size/2;
    double median = size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
    return median;
}
