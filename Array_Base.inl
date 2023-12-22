// -*- C++ -*-
//$Id: Array_Base.inl

//
//size
//
template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
  return this->cur_size_;
}

//
//max_size
//
template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
  return this->max_size_;
}