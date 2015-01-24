#pragma once

#include <algorithm>
#include <iterator>

template <class InputIterator1, class InputIterator2> bool my_equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2) {
    while (b != e) {
        if (*b != *b2) {
            return false;
        }
        b++;
        b2++;
    }
    return true;

}
