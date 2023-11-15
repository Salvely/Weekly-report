#ifndef __HOMEWORK4_H__
#define __HOMEWORK4_H__

#include <algorithm>
#include <array>
#include <initializer_list>
#include <iostream>
#include <string>

namespace ipb {

template <typename T>
class named_vector {
public:
    std::string vec_name;  // name of the vector
    T* vec_data;           // the data of the vector
    int vec_size;          // the size of the vector = size of name + elem_num
    int vec_cap;   // the capacity of the vector, which must >= 2 * elem_num
    int elem_num;  // the number of elements in the vector

    named_vector(std::string name, std::initializer_list<T> data);
    T* data();
    named_vector<T> vector();
    std::string name();
    int size();
    int capacity();
    void resize(int new_size);
    bool empty();
    void reserve(int new_size);
    int ElemNum();
};

template <typename T>
inline named_vector<T>::named_vector(std::string name,
                                     std::initializer_list<T> data) {
    this->vec_name = name;
    this->elem_num = data.size();
    this->vec_cap = 2 * elem_num;
    this->vec_size = name.size() + elem_num;
    this->vec_data = new T[this->vec_cap];
    int i = 0;
    for (auto item : data) {
        vec_data[i] = item;
        i += 1;
    }
}

template <typename T>
inline std::string named_vector<T>::name() {
    return this->vec_name;
}

template <typename T>
inline T* named_vector<T>::data() {
    return this->vec_data;
}

template <typename T>
inline named_vector<T> named_vector<T>::vector() {
    return this;
}

template <typename T>
inline int named_vector<T>::size() {
    return this->vec_size;
}

template <typename T>
inline int named_vector<T>::capacity() {
    return this->vec_cap;
}

template <typename T>
inline void named_vector<T>::resize(int new_size) {
    /**
     * value that could be changed:
     * vec_cap
     * elem_num
     * vec_data
     * vec_size
     */
    if (new_size > this->vec_cap) {
        T* new_data = new T[2 * new_size];
        int i = 0;
        while (i < elem_num) {
            new_data[i] = vec_data[i];
            i++;
        }
        while (i < new_size) {
            new_data[i] = 0;
            i++;
        }
        vec_data = new_data;
        elem_num = new_size;
        vec_cap = 2 * elem_num;
        vec_size = vec_name.size() + elem_num;
    } else if (new_size != elem_num) {
        if (new_size > elem_num) {
            int i = elem_num;
            while (i < new_size) {
                vec_data[i] = 0;
                i++;
            }
        }
        elem_num = new_size;
        vec_size = vec_name.size() + elem_num;
    }
}

template <typename T>
inline bool named_vector<T>::empty() {
    return this->elem_num == 0 || this->vec_name.size() == 0;
}

template <typename T>
inline void named_vector<T>::reserve(int new_size) {
    if (new_size > this->vec_cap) {
        T* new_data = new T[2 * new_size];
        int i = 0;
        while (i < elem_num) {
            new_data[i] = vec_data[i];
            i++;
        }
        vec_data = new_data;
        vec_cap = new_size;
    }
}

template <class T>
inline int named_vector<T>::ElemNum() {
    return elem_num;
}

// a general function that performs the iteration on the vector
// perform some operations depending on the `operation` parameter and the
// condition template <class T> auto operate(named_vector<T> vec, std::string
// operation = "", bool (*)(named_vector<T>))
// {

// }

// returns the sum over all the elements in the data container
template <class T>
T accumulate(named_vector<T>& vec) {
    if (std::is_arithmetic<T>::value) {
        T sum = 0;
        T* data = vec.data();
        for (int i = 0; i < vec.ElemNum(); i++) {
            sum += data[i];
        }
        return sum;
    }
    return 0;
}

// return how many elements are stored in the container
template <class T>
int count(named_vector<T>& vec, T elem) {
    T* data = vec.data();
    int count = 0;
    for (int i = 0; i < vec.ElemNum(); i++) {
        if (data[i] == elem) {
            count += 1;
        }
    }
    return count;
}

// returns true if all values in the container are even, false otherwise
template <class T>
bool all_even(named_vector<T>& vec) {
    if (std::is_arithmetic<T>::value) {
        T* data = vec.data();
        for (int i = 0; i < vec.ElemNum(); i++) {
            if (data[i] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// clamp all the values in the container to a given range [min, max]
template <class T>
void clamp(named_vector<T>& vec, int kMin, int kMax) {
    if (std::is_arithmetic<T>::value) {
        T* data = vec.data();
        for (int i = 0; i < vec.ElemNum(); i++) {
            if (data[i] < kMin) {
                data[i] = kMin;
            } else if (data[i] > kMax) {
                data[i] = kMax;
            }
        }
    }
}

// Fill all the elements in the container with a given value
template <class T>
void fill(named_vector<T>& vec, T val) {
    T* data = vec.data();
    for (int i = 0; i < vec.ElemNum(); i++) {
        data[i] = val;
    }
}

// returns true if a given value is in the container
template <class T>
bool find(named_vector<T>& vec, T val) {
    T* data = vec.data();
    for (int i = 0; i < vec.ElemNum(); i++) {
        if (data[i] == val) {
            return true;
        }
    }
    return false;
}

// print everything inside the container to the standard output
template <class T>
void print(named_vector<T>& vec) {
    std::cout << "\"" << vec.name() << "\":";
    T* data = vec.data();
    for (int i = 0; i < vec.ElemNum(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// converts the name(if any) of the container to upper case
template <class T>
void toupper(named_vector<T>& vec) {
    std::transform(vec.name().begin(), vec.name().end(), vec.vec_name,
                   [](unsigned char c) { return std::toupper(c); });
}

// sort the values in the container
template <class T>
void sort(named_vector<T>& vec) {
    T* data = vec.data();
    for (int i = 0; i < vec.ElemNum(); i++) {
        // find the smallest number index in the array index >= i
        int smallest = i;
        for (int j = i + 1; j < vec.ElemNum(); j++) {
            if (data[j] < data[smallest]) {
                smallest = j;
            }
        }
        // swap the position between i and index
        int temp = data[i];
        data[i] = data[smallest];
        data[smallest] = temp;
    }
}

// shift rotate the values in the container a given number of posissions
template <class T>
void rotate(named_vector<T>& vec, int k) {
    T* shifted = new T[k];
    int size = vec.ElemNum();
    int j = 0;
    T* data = vec.data();
    for (int i = size - k; i < size; i++) {
        shifted[j] = data[i];
        j++;
    }
    for (int i = size - 1; i >= k; i--) {
        data[i] = data[i - k];
    }
    for (int i = 0; i < j; i++) {
        data[i] = shifted[i];
    }
}

// reverse(mirror) the values in the container
template <class T>
void reverse(named_vector<T>& vec) {
    T* data = vec.data();
    int size = vec.ElemNum();
    for (int i = 0; i < size / 2; i++) {
        int temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}

}  // namespace ipb
#endif