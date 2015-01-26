#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstddef>

using std::domain_error;
using std::sort;
using std::vector;
template <class T> T median(vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template <class T, class iter> T median1(iter b, iter e) {

	if (b == e)
		throw domain_error("median of an empty container");

    vector<T> temp; 
    copy(b, e, back_inserter(temp));
    sort(temp.begin(), temp.end());

    size_t size = temp.size();
	size_t mid = size/2;
    T ret = (size % 2 == 0) ? (temp[mid] + temp[mid-1]) / 2 : temp[mid];

	return ret;
}


#endif

