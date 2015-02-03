#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <stdexcept>

template <class T> class Ptr {
public:
    Ptr(): p(0), refptr(new std::size_t(1)) { }
    Ptr(T* t): p(t), refptr(new std::size_t(1)) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }
    Ptr& operator=(const Ptr&);
    ~Ptr();
    //Ptr(T* t): p(t) { }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

    void make_unique() {
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p.clone() : 0;
        }
    }
private:
    T* p;
    std::size_t* refptr;
};

template <class T> Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {
    ++*rhs.refptr;
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T> Ptr<T>::~Ptr<T>() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

template <class T> T& Ptr<T>::operator*() const {
    if (p)
        return *p;
    throw std::runtime_error("unbound handle");
}

template <class T> T* Ptr<T>::operator->() const {
    if (p)
        return p;
    throw std::runtime_error("unbound handle");
}

#endif
