#ifndef GUARD_Ref_handle_h
#define GUARD_Ref_handle_h

#include <stdexcept>

template <class T> class Ref_handle {
public:
    Ref_handle(): p(0), refptr(new std::size_t(1)) { }
    Ref_handle(T* t): p(t), refptr(new std::size_t(1)) { }
    Ref_handle(const Ref_handle& h): p(h.p), refptr(h.refptr) { ++*refptr; }
    Ref_handle& operator=(const Ref_handle&);
    ~Ref_handle();
    //Ref_handle(T* t): p(t) { }

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T* p;
    std::size_t* refptr;
};

template <class T> Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs) {
    ++*rhs.refptr;
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T> Ref_handle<T>::~Ref_handle<T>() {
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

template <class T> T& Ref_handle<T>::operator*() const {
    if (p)
        return *p;
    throw std::runtime_error("unbound handle");
}

template <class T> T* Ref_handle<T>::operator->() const {
    if (p)
        return p;
    throw std::runtime_error("unbound handle");
}

#endif
