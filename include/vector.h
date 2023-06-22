/**
 * @file vector.h
 * @author Richard Nguyen (richard@richardhnguyen.com)
 * @brief An implement of dynamic array for education purpose only
 * @version 0.2
 * @date 2023-06-20
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __DUTCPP_VECTOR_H
#define __DUTCPP_VECTOR_H 1

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>

namespace dutcpp
{
template <typename _Pointer, typename _Container>
class __normal_iterator
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

    constexpr __normal_iterator() noexcept : _current(_Pointer()) { }

    explicit __normal_iterator(const _Pointer &_p) noexcept : _current(_p) { }

    template <typename _Iter,
              typename = typename std::enable_if<
                  std::is_convertible<_Iter, _Pointer>::value, void>::type>
    __normal_iterator(const __normal_iterator<_Iter, _Container> &_i) noexcept
    : _current(_i.base())
    {
    }

    reference
    operator*() const noexcept
    {
        return *_current;
    }

    pointer
    operator->() const noexcept
    {
        return _current;
    }

    __normal_iterator &
    operator++() noexcept
    {
        ++_current;
        return *this;
    }

    __normal_iterator
    operator++(int) noexcept
    {
        return __normal_iterator(_current++);
    }

    __normal_iterator &
    operator--() noexcept
    {
        --_current;
        return *this;
    }

    __normal_iterator
    operator--(int) noexcept
    {
        return __normal_iterator(_current--);
    }

    reference
    operator[](difference_type pos) const noexcept
    {
        return _current[pos];
    }

    __normal_iterator &
    operator+=(difference_type n) noexcept
    {
        _current += n;
        return *this;
    }

    __normal_iterator
    operator+(difference_type n) const noexcept
    {
        return __normal_iterator(_current + n);
    }

    __normal_iterator &
    operator-=(difference_type n) noexcept
    {
        _current -= n;
        return *this;
    }

    __normal_iterator
    operator-(difference_type n) const noexcept
    {
        return ____normal_iterator(_current - n);
    }

    const _Pointer &
    base() const noexcept
    {
        return _current;
    }
};

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator==(const __normal_iterator<_IteratorL, _Container> &lhs,
           const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() == rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator==(const __normal_iterator<_Iterator, _Container> &lhs,
           const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() == rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator!=(const __normal_iterator<_IteratorL, _Container> &lhs,
           const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() != rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator!=(const __normal_iterator<_Iterator, _Container> &lhs,
           const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() != rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<(const __normal_iterator<_IteratorL, _Container> &lhs,
          const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() < rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator<(const __normal_iterator<_Iterator, _Container> &lhs,
          const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() < rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<=(const __normal_iterator<_IteratorL, _Container> &lhs,
           const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() <= rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator<=(const __normal_iterator<_Iterator, _Container> &lhs,
           const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() <= rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>(const __normal_iterator<_IteratorL, _Container> &lhs,
          const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() > rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator>(const __normal_iterator<_Iterator, _Container> &lhs,
          const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() > rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>=(const __normal_iterator<_IteratorL, _Container> &lhs,
           const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
{
    return lhs.base() >= rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool
operator>=(const __normal_iterator<_Iterator, _Container> &lhs,
           const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() >= rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline auto
operator-(const __normal_iterator<_IteratorL, _Container> &lhs,
          const __normal_iterator<_IteratorR, _Container> &rhs) noexcept
    -> decltype(lhs.base() - rhs.base())
{
    return lhs.base() - rhs.base();
}

template <typename _Iterator, typename _Container>
inline typename __normal_iterator<_Iterator, _Container>::difference_type
operator-(const __normal_iterator<_Iterator, _Container> &lhs,
          const __normal_iterator<_Iterator, _Container> &rhs) noexcept
{
    return lhs.base() - rhs.base();
}

template <typename _Iterator, typename _Container>
inline __normal_iterator<_Iterator, _Container>
operator+(typename __normal_iterator<_Iterator, _Container>::difference_type n,
          const __normal_iterator<_Iterator, _Container> &i)
{
    return __normal_iterator<_Iterator, _Container>(i.base() + n);
}

template <typename Tp>
class vector
{
public:
    // Define types for consistency. STL sometimes uses some parts of member
    // types for type checking. However, these are solely for readability.
    using value_type      = Tp;
    using reference       = Tp &;
    using const_reference = const Tp &;
    using pointer         = Tp *;
    using const_pointer   = const Tp *;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;

    using allocator = std::allocator<Tp>;
    using traits_t  = std::allocator_traits<allocator>;

    using iterator               = __normal_iterator<pointer, vector>;
    using const_iterator         = __normal_iterator<const_pointer, vector>;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    /**
     * @brief Default constructor
     *
     * This constructor will construct a vector with zero capacity. New pushing
     * will do the first allocation.
     */
    vector() : _start(), _finish(), _end() { }

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
    explicit vector(size_type count, const_reference value)
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
    vector(const vector &other)
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
        this->_start  = other._start;
        this->_finish = other._finish;
        this->_end    = other._end;

        other._start  = pointer();
        other._finish = pointer();
        other._end    = pointer();
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
                  std::input_iterator_tag>::value>::type>
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
            // See
            // https://stackoverflow.com/questions/14820307/when-to-use-addressofx-instead-of-x
            traits_t::destroy(_alloc, std::addressof(*curr));

        _finish = _start;
        traits_t::deallocate(_alloc, this->_start, n);
    }

    /**
     * @brief Returns a read/write iterator that points to the first element in
     * the vector
     */
    iterator
    begin()
    {
        return iterator(this->_start);
    }

    /**
     * @brief Returns a read iterator that points to the first element in the
     * vector
     */
    const_iterator
    begin() const
    {
        return const_iterator(this->_start);
    }

    /**
     * @brief Returns a read iterator that points to the first element in the
     * vector
     */
    const_iterator
    cbegin() const
    {
        return const_iterator(this->_start);
    }

    /**
     * @brief Returns a read/write iterator that points to one-past the last
     * element in the vector
     */
    iterator
    end()
    {
        return iterator(this->_finish);
    }

    /**
     * @brief Returns a read iterator that points to one-past the last element
     * in the vector
     */
    const_iterator
    end() const
    {
        return const_iterator(this->_finish);
    }

    /**
     * @brief Returns a read iterator that points to one-past the last element
     * in the vector
     */
    const_iterator
    cend() const
    {
        return const_iterator(this->_finish);
    }

    /**
     * @brief Returns a read/write reversed iterator that points to one-past the
     * last element in the vector
     */
    reverse_iterator
    rbegin()
    {
        return reverse_iterator(end());
    }

    /**
     * @brief Returns a read reversed iterator that points to one-past the last
     * element in the vector
     */
    const_reverse_iterator
    rbegin() const
    {
        return const_reverse_iterator(cend());
    }

    /**
     * @brief Returns a read reversed iterator that points to one-past the last
     * element in the vector
     */
    const_reverse_iterator
    crbegin() const
    {
        return const_reverse_iterator(cend());
    }

    /**
     * @brief Returns a read/write reversed iterator that points to the first
     * element in the vector
     */
    reverse_iterator
    rend()
    {
        return reverse_iterator(begin());
    }

    /**
     * @brief Returns a read reversed iterator that points to the first element
     * in the vector
     */
    const_reverse_iterator
    rend() const
    {
        return const_reverse_iterator(cbegin());
    }

    /**
     * @brief Returns a read reversed iterator that points to the first element
     * in the vector
     */
    const_reverse_iterator
    crend() const
    {
        return const_reverse_iterator(cbegin());
    }

    /**
     * @brief Checks if the vector has no element
     */
    _GLIBCXX_NODISCARD bool
    empty() const
    {
        // Assume _start and _finish are correctly positioned, then _start ==
        // _finish means there is no element in the vector.
        return begin() == end();
    }

    /**
     * @brief Returns the number of elements in the vector
     */
    size_type
    size() const
    {
        return std::distance(begin(), end());
    }

    /**
     * @brief Returns the capacity of elements in the vector
     */
    size_type
    capacity() const
    {
        return this->_end - this->_start;
    }

    /**
     * @brief Destroys all elements in this vector
     *
     * After calling this method, size() == 0 and capacity() will remain
     * unchanged.
     */
    void
    clear() noexcept
    {
        if (size() <= 0)
            return;

        for (auto curr = begin(); curr != end(); ++curr)
            // See
            // https://stackoverflow.com/questions/14820307/when-to-use-addressofx-instead-of-x
            traits_t::destroy(_alloc, std::addressof(*curr));

        this->_finish = this->_start;
    }

    iterator
    insert(const_iterator pos, const_reference value)
    {
        const size_type n  = pos - begin();
        const auto new_pos = begin() + (pos - cbegin());

        // Enough space?
        if (_finish != _end)
        {
            // Insert back?
            if (pos == cend())
            {
                traits_t::construct(_alloc, _finish, value);
                ++_finish;
            }
            // Shifting needed
            else
                _shift_insert(new_pos, value);
        }
        // Reallocation needed
        else
        {
            _realloc_insert(new_pos, value);
        }

        return iterator(_start + n);
    }

private:
    allocator _alloc;
    pointer _start;
    pointer _finish;
    pointer _end;

    size_type
    _check_len(size_type n, const char *s) const
    {
        if (traits_t::max_size(_alloc) - size() < n)
            std::__throw_length_error("New size exceeds max_size()");

        const size_type len = size() + std::max(size(), n);

        return (len < size() || len > traits_t::max_size(_alloc))
                   ? traits_t::max_size(_alloc)
                   : len;
    }

private:
    void
    _fill_initialize(size_type count, const_reference value)
    {
        this->_start  = traits_t::allocate(_alloc, count);
        this->_finish = this->_start;
        this->_end    = this->_start + count;

        for (size_type i = 0; i < count; ++i)
            traits_t::construct(_alloc, this->_finish++, value);
    }

    template <class InputIter>
    void
    _range_initialize(InputIter first, InputIter last)
    {
        size_type n   = std::distance(first, last);
        this->_start  = traits_t::allocate(_alloc, n);
        this->_finish = this->_start;
        this->_end    = this->_start + n;

        for (auto it = first; it != last; ++it)
            traits_t::construct(_alloc, this->_finish++, *it);
    }

    template <typename Arg>
    void
    _shift_insert(const_iterator pos, Arg &&arg)
    {
        // Using Arg template for forwarding for all types of passing (values,
        // reference, remove value).

        const auto new_pos = begin() + (pos - cbegin());

        // Shift the last element to the right
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | x | x | x |                      //
        // ---------------------------------------------                      //
        //                      v
        //                                       _f
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 7 | x | x |                      //
        // ---------------------------------------------                      //
        traits_t::construct(_alloc, std::addressof(*_finish),
                            std::move(*(_finish - 1)));
        ++_finish;

        //                   f           l   e   _f
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 7 | x | x |                      //
        // ---------------------------------------------                      //
        pointer first = new_pos.base(); // First to shift
        pointer last  = _finish - 2;    // Last to shift
        pointer end   = _finish - 1;    // One-past last

        //                 f = l e              _f
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | 4 | 4 | 5 | 6 | 7 | x | x |                      //
        // ---------------------------------------------                      //
        while (first != last)
            *(--end) = *(--last);

        //                   f
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | a | 4 | 5 | 6 | 7 | x | x |                      //
        // ---------------------------------------------                      //
        *new_pos = std::forward<Arg>(arg);
    }

    template <typename Arg>
    void
    _realloc_insert(iterator pos, Arg arg)
    {

        pointer old_start  = this->_start;
        pointer old_finish = this->_finish;
        pointer old_end    = this->_end;

        //                   x
        //                   v
        // -----------------------------------------                          //
        // | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |                          //
        // -----------------------------------------                          //

        // Allocate a new array
        const size_type new_len = _check_len(1, "vector::insert");
        pointer new_start       = traits_t::allocate(_alloc, new_len);
        pointer new_finish      = pointer();

        const difference_type n = pos - begin();

        // (1)                                                                //
        // ---------------------------------------------                      //
        // | ? | ? | ? | ? | x | ? | ? | ? | ? | ? | ? |                      //
        // ---------------------------------------------                      //
        // (2)                                                                //
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | x | ? | ? | ? | ? | ? | ? |                      //
        // ---------------------------------------------                      //
        // (3)                                                                //
        // ---------------------------------------------                      //
        // | 0 | 1 | 2 | 3 | x | 4 | 5 | 6 | 7 | 8 | 9 |                      //
        // ---------------------------------------------                      //
        try
        {
            // Construct first to accomodate catch block if there is an error

            // (1)
            traits_t::construct(_alloc, new_start + n, std::forward<Arg>(arg));

            // (2)
            new_finish =
                std::uninitialized_move(old_start, pos.base(), new_start);
            ++new_finish;

            // (3)
            new_finish =
                std::uninitialized_move(pos.base(), old_finish, new_finish);
        }
        catch (...)
        {
            if (!new_finish)
                traits_t::destroy(_alloc, new_start + n);
            else
                for (auto curr = new_start; curr != new_finish; curr++)
                    traits_t::destroy(_alloc, std::addressof(*curr));

            traits_t::deallocate(_alloc, new_start, new_len);
        }

        for (pointer curr = old_start; curr != old_finish; curr++)
            traits_t::destroy(_alloc, std::addressof(*curr));
        traits_t::deallocate(_alloc, old_start, _end - old_start);

        this->_start  = new_start;
        this->_finish = new_finish;
        this->_end    = new_start + new_len;
    }
};
} // namespace dutcpp

#endif
