#pragma once

#include <algorithm>
#include <iterator>

template <class Bi> void book_reverse(Bi begin, Bi end) {
    while (begin != end) {
        --end;
        if (begin != end) {
            //std::swap(*begin++, *end);
            my_swap(*begin++, *end);
        }
    }
}

template <class X> void my_swap(X& a, X&b) {
    X c = a;
    a = b;
    b = c;
    return;
}
