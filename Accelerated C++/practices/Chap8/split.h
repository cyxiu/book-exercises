#ifndef GUARD_split_h
#define GUARD_split_h

#include <iterator>
#include <string>
#include <algorithm>
#include <cctype>

using std::find_if;
using std::isspace;
using std::string;


inline bool space(char c) {
  return isspace(c);
}

inline bool not_space(char c) {
  return !isspace(c);
}

template <class Out> void split(const std::string& str, Out os) {
    typedef std::string::const_iterator iter;
    iter i = str.begin();
    while(i != str.end()) {
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        if (i != str.end()) {
            *os++ = string(i, j);
        }
        i = j;
    }
}

#endif
