// $Id: Stack.cpp 
#include "Stack.h"

//
// Stack
//construct the stack array member variable 
template <typename T>
Stack <T>::Stack (void)
    : aStack_ ()
{}

//
// Stack
// construct the stack array using arrays copy constructor
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : aStack_ (Array<T>(stack.aStack_))
{}

//
// ~Stack
// no need to deconstruct. array deconstructor handles that
template <typename T>
Stack <T>::~Stack (void)
{}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // Check if the stack is full and needs resizing.
    if (this->size() == this->aStack_.max_size()) {
        this->aStack_.resize(this->size() + 5);
    }
    
    // Add the element to the stack and increment the size.
    this->aStack_.set(this->size(), element);
    this->aStack_.resize(this->size() + 1);
}


//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    //make sure that stack is not empty
    if (this -> is_empty()){
        throw empty_exception();
    }
    else {
        //  simply just resize to size - 1 and the cur size will be decreased
        //  so if new elements are pushed then ultimetly they will replace the preserved data
        this -> aStack_.resize(this -> size() - 1);
    }
}

//
// peekPop
//
template <typename T>
T Stack <T>::peekPop (void)
{
    //make sure that stack is not empty
    if (this -> is_empty()){
        throw empty_exception();
    }
    else {
        // Grab the top element before popping
        T element = this->top();
        // pop the stack
        this->pop();
        // return the grabbed element
        return element;
    }
}

//
// operator =
//
template <typename T>
const Stack<T> & Stack <T>::operator = (const Stack & rhs)
{
    //check for no self assignment
    if (this != &rhs) {
        // COMMENT It would be easier if you just use the assignment operator
        // on the array to copy things from rhs.
        
        /**
         * @brief 
         *      RESPONSE:
         *          I see now that re implementing the sam method is useless and smelly.
         *          i deleted the code and i use the arrays assignment operator for the stacks assignment operation.
         * 
         */
        this->aStack_ = rhs.aStack_;

    }
    //return this stack whether it was changed or not
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //simply just resize array to 0
    this -> aStack_.resize(0);
}
