// -*- C++ -*-
// $Id: Stack.inl
//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    //return the arrays size from aStack_
    return this -> aStack_.size();
}

//
// top
// checks if stack is empty
//      if empty it throws empty_exception
// returns the value at stack size - 1 (top)
template <typename T>
inline
T Stack <T>::top (void) const
{
    if (this -> is_empty())
        throw empty_exception();
    return aStack_.get(this -> size() - 1);
}

//
// is_empty
//check if the arrays size is == 0
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return (this -> size() == 0);
}
