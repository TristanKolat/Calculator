#ifndef _EXPR_ITERATOR_
#define _EXPR_ITERATOR_

/**
 * @class Expr_Iterator
 * @brief An general interface of essential operations for iterating over a collection of expressions.
 *
 * @tparam T The type of elements that the iterator will handle.
 */
template <typename T>
class Expr_Iterator {
public:
    /**
     * Virtual destructor
     */
    virtual ~Expr_Iterator() {}

    /**
     * Checks whether the iteration has reached its end.
     *
     * @return True if there are no more elements to iterate over; false otherwise.
     */
    virtual bool is_done(void) const = 0;

    /**
     * Advances the iterator to the next element
     */
    virtual void advance(void) = 0;

    /**
     * Dereferences the iterator to access the value it currently points to.
     *
     * @return A reference to the current element
     */
    virtual T& operator * (void) = 0;

    /**
     * Provides pointer-like access to the member functions of the current element.
     *
     * @return A pointer to the current element
     */
    virtual T* operator -> (void) = 0;
};

#endif // _EXPR_ITERATOR_
