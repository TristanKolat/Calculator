// $Id: ArrayBase.h 2023-10-3 by Tristan Kolat$

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"      // header file
#include <cstring>          // library for size_t definition
#include <stdexcept>        // library for std::out_of_bounds exception

#define DEFAULT 7           //for defaulting array to 7 during default construction

/*  
    ==============================================================
    ===========================CONSTRUCTORS=======================
    ==============================================================
*/

/* 
    Default Construct:
        Array_Base(void)
*/
template <typename T>
Array_Base <T>::Array_Base (void)
    : data_ (new T [DEFAULT]),
      cur_size_ (0),
      max_size_ (DEFAULT)
{}

/* 
    Length Construct:
        Array_Base(size_t)
*/
template <typename T>
Array_Base <T>::Array_Base (size_t length)
    : data_ (new T [length == 0 ? DEFAULT : length]),
      cur_size_ (0),
      max_size_ (length == 0 ? DEFAULT : length)
{}

/* 
    Fill Construct:
        Array_Base(size_t, char)
*/
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
    : Array_Base (length)    
{
    //fill data's length of the array with a specific character
    this -> fill(fill);
    this->cur_size_ = length;
}

/* 
    Copy Construct:
        Array_Base (const Array_Base & arr)
*/
template <typename T>
Array_Base <T>::Array_Base (const Array_Base <T> & arr)
    : Array_Base (arr.max_size())
{
    for (size_t iter = 0; iter < arr.size(); iter++) {
        this -> set(iter, arr.data_[iter]);
    }
    this->cur_size_ = arr.size();
}

/* 
    Destruct:
        ~Array_Base
*/
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    if (data_ != nullptr) {
        delete [] data_;
    }    
}

/*
    =============================================================
    ==========================OPERATORS==========================
    =============================================================
*/

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index < this->cur_size_) {
        return this->data_[index];
    }
    else { //if out of range then throw exception
        throw std::out_of_range("Invalid index");
    }
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index < this->cur_size_) {
        return this->data_[index];
    }
    else { //if out of range then throw exception
        throw std::out_of_range("Invalid index");
    }
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base <T> & rhs) const
{
    //check for no self assignment
    if (this != &rhs) {
        //check if array sizes are equal
        if (this->size() == rhs.cur_size_) {
            //check every element in data's contents
            for (size_t i = 0; i < this->size(); i++) {
                //check for mismatches
                if (data_[i] != rhs.data_[i]) {
                    //if there is a mismatch then arrays are not equal (return false)
                    return false;
                }
            }
            //return true if for loop doesnt find mismatch
            return true;
        } else { //return false if cur_size's dont match
            return false;
        }
    }
    return true; //default return statement
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base <T> & rhs) const
{
    return ! (*this == rhs);
}

/*  =============================================================
    ===========================Methods===========================
    =============================================================*/

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (size_t i = 0; i < this->max_size(); i++) {
        this->set(i, value);
    }
}    

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    //check contents of Array_Base for first occurance of the value
    return this -> find (value, 0);
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    //check if start index is within range of the Array_Base
    if (start < this->size()) {
        //check data contents for first occurance of the value
        for (size_t index = start; index < cur_size_; index++) {
        //once value is found return the index (i)
            if (data_[index] == val) {
                return index;
            }
        }
        //if value was not found return -1
        return -1;
    }
    //if out of range then throw exception
    else {
        throw std::out_of_range("Invalid index value");
    }
}

// Non-const version
template <typename T>
T& Array_Base<T>::get(size_t index)
{
    if (index < this->cur_size_) {
        return this->data_[index];
    } else {
        throw std::out_of_range("Invalid index");
    }
}

// Const version
template <typename T>
const T& Array_Base<T>::get(size_t index) const
{
    if (index < this->cur_size_) {
        return this->data_[index];
    } else {
        throw std::out_of_range("Invalid index");
    }
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    //check if index is within range
    if (index < this -> max_size()) {

        this->data_[index] = value;
    }    
    else { //if out of range then throw exception
        throw std::out_of_range("Invalid index");
    }
}