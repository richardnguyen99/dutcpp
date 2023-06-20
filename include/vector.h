/**
 * @file vector.h
 * @author Richard Nguyen (richard@richardhnguyen.com)
 * @brief An implement of dynamic array for education purpose only
 * @version 0.1
 * @date 2023-06-20
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __DUTCPP_VECTOR_H
#define __DUTCPP_VECTOR_H 1

#include <cstddef>
#include <memory>
#include <initializer_list>
#include <iterator>

namespace dutcpp
{
template <typename _Pointer, typename _Container>
class normal_iterator
{
protected:
    _Pointer _current;

    using traits_type = std::iterator_traits<_Pointer>;

public:
    using iterator_type     = _Pointer;
    using iterator_category = typename traits_type::iterator_category;
    using value_type        = typename traits_type::value_type;
    using difference_type   = typename traits_type::difference_type;
    using reference         = typename traits_type::reference;
    using pointer           = typename traits_type::pointer;

    constexpr normal_iterator() noexcept : _current(_Pointer()) {}

    explicit normal_iterator(const _Pointer &_p) noexcept : _current(_p) {}

    template <typename _Iter>
    normal_iterator(
        const normal_iterator<
            _Iter, typename std::enable_if<
                        (std::is_same<
                            _Iter, typename _Container::pointer>::__value),
                        _Container>::__type> &_i) noexcept
        : _current(_i._current)
    {
    }

    reference operator*() const noexcept { return *_current; }

    pointer operator->() const noexcept { return _current; }

    normal_iterator &operator++() noexcept
    {
        ++_current;
        return *this;
    }

    normal_iterator operator++(int) noexcept
    {
        return normal_iterator(_current++);
    }

    normal_iterator &operator--() noexcept
    {
        --_current;
        return *this;
    }

    normal_iterator operator--(int) noexcept
    {
        return normal_iterator(_current--);
    }

    reference operator[](difference_type pos) const noexcept
    {
        return _current[pos];
    }

    normal_iterator &operator+=(difference_type n) noexcept
    {
        _current += n;
        return *this;
    }

    normal_iterator operator+(difference_type n) const noexcept
    {
        return normal_iterator(_current + n);
    }

    normal_iterator &operator-=(difference_type n) noexcept
    {
        _current -= n;
        return *this;
    }

    normal_iterator operator-(difference_type n) const noexcept
    {
        return normal_iterator(_current - n);
    }

    const _Pointer &base() const noexcept { return _current; }
};

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator==(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() == rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator==(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() == rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator!=(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() != rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator!=(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() != rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() < rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator<(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() < rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<=(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() <= rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator<=(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() <= rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() > rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator>(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() > rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>=(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() >= rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator>=(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() >= rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline auto
operator-(const normal_iterator<_IteratorL, _Container> &lhs,
            const normal_iterator<_IteratorR, _Container> &rhs) noexcept
    -> decltype(lhs.base() - rhs.base())
{
    return lhs.base() - rhs.base();
}

template <typename _Iterator, typename _Container>
inline typename normal_iterator<_Iterator, _Container>::difference_type
operator-(const normal_iterator<_Iterator, _Container> &lhs,
            const normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() - rhs.base();
}

template <typename _Iterator, typename _Container>
inline normal_iterator<_Iterator, _Container> operator+(
    typename normal_iterator<_Iterator, _Container>::difference_type n,
    const normal_iterator<_Iterator, _Container>                    &i)
{
    return normal_iterator<_Iterator, _Container>(i.base() + n);
}


template <typename Tp>
class vector
{
public:
    // Define types for consistency
    using value_type = Tp;
    using reference = Tp &;
    using const_reference = const Tp &;
    using pointer = Tp*;
    using const_pointer = const Tp*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    using allocator = std::allocator<Tp>;
    using traits_t = std::allocator_traits<allocator>;

    /**
     * @brief Default constructor
     * 
     * This constructor will construct a vector with zero capacity. New pushing
     * will do the first allocation.
     */
    vector() 
    : _start(), _finish(), _end() 
    {
    }

    /**
     * @brief Default fill constructor
     * 
     * This constructor will construct a vector and fill in the vector with 
     * %count elements. The value of all elements are the default value defined
     * by %value_type.
     */
    explicit vector(size_type count)
    {
        // Call to value_type() will invoke the default value for value_type.
        // For example, if value_type (Tp) is an int, calling int() will be 0.
        // For customized object, the value_type object must support default
        // constructor. 
        _fill_initialize(count, value_type());
    }

    /**
     * @brief Fill constructor with specified value
     * 
     * Same as default fill constructor. But instead of filling default value,
     * the value of filled elements is a copy of the parameter %value.
     */
    explicit vector (size_type count, const_reference value)
    {
        _fill_initialize(count, value);
    }

    /**
     * @brief Copy constructor
     * 
     * This constructor will construct a new vector object and copy the data 
     * from the %other vector to this newly-created vector. The original vector
     * is guaranteed to have its data unmodified.
     */
    vector(const vector& other) 
    {
        _range_initialize(std::cbegin(other), std::cend(other));
    }

    /**
     * @brief Move constructor
     * 
     * This constructor will construct a new vector object and transfer the 
     * ownership from the %other vector to the newly-created vector. It 
     * guarantees there is no copy happening.
     */
    vector(vector &&other)
    {
        this->_start = other._start;
        this->_finish = other._finish;
        this->_end = other._end;

        other._start = pointer();
        other._finish = pointer();
        other._end = pointer();
    }

    /**
     * @brief Range constructor
     * 
     * This constructor will construct a new vector object and fill in the 
     * vector with the data in the iterator range [first, last). 
     * 
     * If a container supports iterator methods such `begin()` and `end()`, it
     * will behave just like copy constructor, but the other object can be a 
     * different class.
     */
    template <class InputIter, 
        typename = typename ::std::enable_if<std::is_convertible<
            typename std::iterator_traits<InputIter>::iterator_category,
            std::input_iterator_tag
        >::value>::type
    >
    vector(InputIter first, InputIter last)
    {
        // The reason why we need to add type check on InputIter is to remove
        // the ambiguity with the overload (size_type, value_type).
        // This is enabled if and only if InputIter can be converted to input
        // iterator tag defined by STD.
        _range_initialize(first, last);
    }

    /**
     * @brief List constructor
     * 
     * This constructor will construct a new vector object and fill in the 
     * vector with the data from the %init list.
     */
    vector(std::initializer_list<value_type> init)
    {
        _range_initialize(init.begin(), init.end());
    }

    ~vector() 
    {
        const difference_type n = std::distance(this->_start, this->_finish);

        for (auto curr = this->_start; curr != this->_finish; ++curr)
            // See https://stackoverflow.com/questions/14820307/when-to-use-addressofx-instead-of-x
            traits_t::destroy(_alloc, std::addressof(*curr));

        _finish = _start;
        traits_t::deallocate(_alloc, this->_start, n);
    }


private:
    allocator _alloc;
    pointer _start;
    pointer _finish;
    pointer _end;


private: 
    void _fill_initialize(size_type count, const_reference value)
    {
        this->_start = traits_t::allocate(_alloc, count);
        this->_finish = this->_start;
        this->_end = this->_start + count;

        for (size_type i = 0; i < count; ++i)
            traits_t::construct(_alloc, this->_finish++, value);

    }

    template<class InputIter>
    void _range_initialize(InputIter first, InputIter last)
    {
        size_type n = std::distance(first, last);
        this->_start = traits_t::allocate(_alloc, n);
        this->_finish = this->_start;
        this->_end = this->_start + n;

        for (auto it = first; it != last; ++it)
            traits_t::construct(_alloc, this->_finish++, *it);
    }
};
}

#endif
