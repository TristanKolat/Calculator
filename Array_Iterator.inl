// -*- C++ -*-

#include "Array_Iterator.h"

// Constructor
template <typename T>
inline
Array_Iterator<T>::Array_Iterator(Array<T> &a)
    : a_(a), 
    curr_(0) 
{}

template <typename T>
inline
Array_Iterator<T>::~Array_Iterator() 
{}

template <typename T>
inline
bool Array_Iterator<T>::is_done(void) const {
    return this->curr_ >= this->a_.size();
}

template <typename T>
inline
void Array_Iterator<T>::advance(void) {
    this->curr_++;
}

template <typename T>
inline
size_t Array_Iterator<T>::Index(void) {
    return this->curr_;
}

template <typename T>
inline
T& Array_Iterator<T>::operator * (void) {
    return this->a_[this->curr_];
}

template <typename T>
inline
T* Array_Iterator<T>::operator -> (void) {
    return &(this->a_[this->curr_]);
}

