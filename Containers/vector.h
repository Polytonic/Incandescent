#ifndef INCANDESCENT_CONTAINER_VECTOR
#define INCANDESCENT_CONTAINER_VECTOR
#pragma once

namespace ist {
    template <typename T>
    class vector {
    public:
        using value_type = T;
        using size_type = unsigned long long;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    private:
        size_type num_elements = 0;
        size_type container_size = 2 << 3;
        value_type* container = new value_type[container_size];

    public:
        vector() = default;
        ~vector() {
            delete[] this->container;
        }

        /// Element Access

        reference at(size_type position) {}
        const_reference at(size_type position) const {}

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

        reference front() {}
        const_reference front() const {}
        reference back() {}
        const_reference back() const {}
        pointer data() noexcept {}
        const_pointer data() const noexcept {}

        /**

         */
        void push_back(const value_type& value) {
            // Check Whether Insertion Exceeds Available Capacity
            if (this->num_elements >= this->container_size) {
                // Reallocate a Larger Container
                auto expanded_container_size = this->container_size * 2;
                auto expanded_container = new value_type[expanded_container_size];

                // Copy Existing Elements into Larger Container
                for (vector<value_type>::size_type i = 0; i < this->container_size; ++i) {
                    expanded_container[i] = this->container[i];
                }

                // Free Existing Container and Reassign Larger Container
                delete[] this->container;
                this->container = expanded_container;
                this->container_size = expanded_container_size;
            }

            // Insert the Given Element
            this->container[num_elements++] = value;
        }

        /**

         */
        size_type size() const noexcept {
            return this->num_elements;
        }

    };  //~ class vector
};      //~ namespace ist
#endif  //~ INCANDESCENT_CONTAINER_VECTOR
