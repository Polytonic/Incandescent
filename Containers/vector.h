/**
    The MIT License (MIT)

    Copyright (c) 2017 Kevin Fung

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software
    and associated documentation files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or
    substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef INCANDESCENT_CONTAINER_VECTOR
#define INCANDESCENT_CONTAINER_VECTOR
#pragma once
#include <limits>

namespace ist {

/**

 */
template <typename T>
class vector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

private:
    size_type element_count = 0;
    size_type container_size = 2 << 3;
    pointer container = new value_type[container_size];
    size_type reallocation_coefficient = 2;

public:
    vector() = default;
    ~vector() {
        delete[] this->container;
    }

    /******************
     * Element Access *
     ******************/

    /**
        @brief Returns a reference to the element at specified location `position`, with bounds
               checking. If `position` is not within the range of the container, an exception of
               type `std::out_of_range` is thrown.

        @note http://en.cppreference.com/w/cpp/container/vector/at
        @param position the position of the element to return.
        @return reference to the requested element.
     */
    reference at(size_type position) {
        if (position < this->element_count) {
            return this->container[position];
        }
        throw std::out_of_range("vector subscript out of range");
    }

    /**
        @brief Returns a reference to the element at specified location `position`, with bounds
               checking. If `position` is not within the range of the container, an exception of
               type `std::out_of_range` is thrown.

        @note http://en.cppreference.com/w/cpp/container/vector/at
        @param position the position of the element to return.
        @return reference to the requested element.
     */
    const_reference at(size_type position) const {
        if (position < this->element_count) {
            return this->container[position];
        }
        throw std::out_of_range("vector subscript out of range");
    }

    /**

     */
    reference operator[](size_type position) {
        return this->container[position];
    }

    /**

     */
    const_reference operator[](size_type position) const {
        return this->container[position];
    }

    /**

     */
    reference front() {
        return this->container[0];
    }

    /**

     */
    const_reference front() const {
        return this->container[0];
    }

    /**

     */
    reference back() {
        return this->container[element_count - 1];
    }

    /**

     */
    const_reference back() const {
        return this->container[element_count - 1];
    }

    /**

     */
    pointer data() noexcept {
        return this->container;
    }

    /**

     */
    const_pointer data() const noexcept {
        return this->container;
    }

    /**

     */
    bool empty() const noexcept {
        return (element_count == 0) ? true : false;
    }

    /**

     */
    size_type size() const noexcept {
        return this->element_count;
    }

    /**

     */
    size_type max_size() const noexcept {
        return std::numeric_limits<size_type>::max();
    }

    /**

     */
    void push_back(const value_type& value) {
        // Check Whether Insertion Exceeds Available Capacity
        if (this->element_count >= this->container_size) {
            // Allocate a Larger Replacement Container
            auto expanded_container_size = this->container_size * reallocation_coefficient;
            auto expanded_container = new value_type[expanded_container_size];

            // Copy Existing Elements into Larger Container
            for (size_type i = 0; i < this->container_size; ++i) {
                expanded_container[i] = this->container[i];
            }

            // Free Existing Container and Reassign Larger Container
            delete[] this->container;
            this->container = expanded_container;
            this->container_size = expanded_container_size;
        }

        // Insert the Given Element
        this->container[element_count++] = value;
    }

};      //~ class vector
};      //~ namespace ist
#endif  //~ INCANDESCENT_CONTAINER_VECTOR
