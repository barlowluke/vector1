#pragma once
#include <stdexcept>
#include <algorithm>  //for std::max

namespace dsa{

template <typename T>
class Vector {

private:
    int cap{0};
    int sz{0};
    T* data{nullptr};

public:
    //empty
    Vector() = default;    

    //capacity
    int capacity() const {
        return cap;
    }

    //elements stored
    int size() const {
        return sz;
    }
    
    // True is empty
    bool empty() const {
        if (sz == 0) {
            return true;
        }
        return false;
    }
    
    //element at index when vector is const
    const T& operator[](int i) const {
        return data[i];
    }
    
    //element at index when vector is non-const
    T& operator[](int i) {
        return data[i];
    }
    
    // at function for const
    const T& at(int i) const {
        if (i < 0 || i >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[i];
    }
    
    // first element
    const T& front() const {
        return data[0];
    }

    // first element
    T& front() {
        return data[0];
    }
    
    // last element
    const T& back() const {
        return data[sz - 1];
    }

    // last element
    T& back() {
        return data[sz - 1];
    }
    
    // insert at end
    void push_back(const T& elem) {
        if (sz == cap) {
            reserve(std::max(1, 2 * cap));
        }
        data[sz] = elem;
        sz += 1;
    }

    // remove from end
    void pop_back() {
      // no validation to check the size, pop_back should be called when 
      // size >= 1
      sz = sz -= 1;
      shrink();
    }

    // insert at index
    void insert(int i, const T& elem) {
        if (sz == cap) {
            reserve(std::max(1, 2 * cap));
        }
        for (int k = sz - 1; k >= i; k--) {
            data[k+1] = data[k];
        }
        data[i] = elem;
        sz = sz += 1;
    }

    // removes at index
    void erase(int i) {
        for (int k = i + 1; k < sz; k++) {
            data[k - 1] = data[k];
        }
        sz = sz -= 1;
        shrink();
    }

    //capacity >= minimum
    void reserve(int minimum) {
        if (cap < minimum) {
            T* new_array = new T[minimum];
            for (int k = 0; k < sz; k++) {
                new_array[k] = data[k];
            }
            delete[] data;
            data = new_array;
            cap = minimum;
        }
    }

    void reallocate(int new_cap) {
        if (new_cap == cap) {
            return;
        }
        T* temp = new T[new_cap];
        for (int k = 0; k < sz; k++) {
            temp[k] = data[k];
        }
        delete[] data;
        data = temp;
        cap = new_cap;
    }

    // called by other functions to reduce cap by half 
    // when sz <= cap/4 
    void shrink() {
        if (cap > 0 && sz <= cap / 4) {
            int new_cap = std::max(1, cap / 2);
            reallocate(new_cap);
        }
    }
    
    // explicitly reduce the cap to sz and keep at least 1 slot
    void shrink_to_fit() {
        if (cap > sz) {
            int new_cap = std::max(1, sz);
            reallocate(new_cap);
        }
    }

}; //end class Vector
}//end namespace dsa
