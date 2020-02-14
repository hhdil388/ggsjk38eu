#pragma once

#include <cstdint>
#include <exception>

template<typename T, std::size_t N>
struct My_container
{
public:

    using value_type        = T;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using size_type         = std::size_t;
    using iterator          = value_type*;

    My_container();
    ~My_container();

    constexpr size_type size();
    constexpr bool empty();

    void push_back(const value_type& value);

    reference at(size_type i); 
    reference operator[](size_type i);
    const_reference operator[](size_type i) const;
    iterator begin();
    iterator end();

private:

    value_type  *_data;
    size_type   _size;
    size_type   _sizeBuf;

    void _allocate(size_type count);
    void _deallocate();
};