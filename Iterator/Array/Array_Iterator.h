#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_


#include "../Interface/Expr_Iterator.h"
#include "../../Array/Array.h"

/**
 * @class Array_Iterator
 * @brief An iterator for traversing elements in an array.
 *
 * @tparam T The type of elements stored in the array.
 */
template <typename T>
class Array_Iterator : public Expr_Iterator<T> {
    public:
        Array_Iterator(Array<T> &a);    // Constructor
        ~Array_Iterator();           // De-Constructor

        /**
         * @return True if the iterator is at the end of the array; false otherwise.
         */
        virtual bool is_done(void) const;

        /**
         * Advances the iterator to the next element in the array
         */
        virtual void advance(void);

        /**
         * Returns the current index
         */
        size_t Index(void);

        /**
         * @return A reference to the element at the current iterator position.
         */
        virtual T& operator * (void);

        /**         *
         * @return A pointer to the element at the current iterator position.
         */
        virtual T* operator -> (void);

    private:
        Array<T> & a_;
        size_t curr_;
};

#include "Array_Iterator.inl"

#endif // _ARRAY_ITERATOR_H_
