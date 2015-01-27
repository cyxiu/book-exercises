#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <cstring>
#include "Vec.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);
public:
    typedef Vec<char>::size_type size_type;
    Str() { prt("default constructor called"); }
    Str(size_type n, const char& c): data(n, c) { prt("n char& constructor called"); } 
    Str(const char* cp) {
        prt("char* constructor called");
        std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
    }
    template <class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }
    ~Str() { prt("destructor called"); }

    char& operator[](size_type i) { 
        //prt("oper[] called"); 
        return data[i];
    }
    const char& operator[](size_type i) const { 
        //prt("const oper[] called");
        return data[i];
    }
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }
    operator bool() const { return (size() > 0); }

    size_type size() const { return data.size(); }

    typedef char* iterator;
    typedef const char* const_iterator;

    iterator begin() { return data.begin(); }
    const_iterator begin() const { return data.begin(); }

    iterator end() { return data.end(); }
    const_iterator end() const { return data.end(); }

    void copy(iterator it, size_type n) const {
        size_type l = std::min(size(), n);
        std::copy(begin(), begin()+l, it);
        return;
    }

    //my own thing
    void print() const {
        std::cout << '-';
        for(Vec<char>::const_iterator i = data.begin(); i != data.end(); i++) {
            std::cout << *i;
        }
        std::cout << '-' << std::endl;
        return;
    }
    void prt(const char* p) const {
        std::cout << p << std::endl;
        return;
    }

private:
    Vec<char> data;

};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);
Str operator+(const char*, const Str&);
Str operator+(const Str&, const char*);


inline bool operator<(const Str& lhs, const Str& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

inline bool operator>(const Str& lhs, const Str& rhs) {
    return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

inline bool operator<=(const Str& lhs, const Str& rhs) {
    return !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

inline bool operator>=(const Str& lhs, const Str& rhs) {
    return !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

inline bool operator==(const Str& lhs, const Str& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

inline bool operator!=(const Str& lhs, const Str& rhs) {
    return !(lhs == rhs);
}


#endif
