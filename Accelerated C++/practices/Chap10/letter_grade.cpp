#include <cstddef>

#include "letter_grade.h"

using std::string;

std::string letter_grade(double grades) {
    static const double numbers[] = {
        97, 94, 90, 87, 64, 0
    };

    static const char* const letters[] = {
        "A+", "A", "A-", "B", "CCC", "F"
    };

    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

    for (size_t i = 0; i < ngrades; i++) {
        if (grades >= numbers[i])
            return letters[i];
    }
    return "?\?\?";
}
