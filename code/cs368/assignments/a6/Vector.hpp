////////////////////////////////////////////////////////////////////////////////
// File Name:      Vector.hpp
//
// Author:         <Your Name>
// CS email:       <Your CS email>
//
// Description:    A custom vector class with a subset
//                 of features from std::vector
////////////////////////////////////////////////////////////////////////////////

#ifndef A6_VECTOR_HPP
#define A6_VECTOR_HPP

#include <cstdio>
#include <iostream>
#include <stdexcept>

/**
 * @brief A templated sequence container that encapsulates dynamic size arrays.
 */
template<typename T>
class Vector {
private:
    T *elems;
    std::size_t capacity;
    std::size_t size;
    static const std::size_t initialCapacity = 4;
    /* If you want to add methods, add them below this line */

    /* If you want to add methods, add them above this line */

public:
    /**
     * @brief Default Constructor.
     */
    Vector() {
        // TODO: implement this function.
    }

    /**
     * @brief Copy Constructor.
     * @param other The vector from which we should copy from.
     */
    Vector(const Vector &other) {
        // TODO: implement this function.
    }

    /**
     * @brief Copy Assignment Operator.
     * @param other The vector on the RHS of the assignment.
     * @return A reference to the vector on the LHS.
     */
    Vector &operator=(const Vector &other) {
        // TODO: implement this function.
    }

    /**
     * @brief Destructor.
     */
    ~Vector(){
        // TODO: implement this function.
    }

    typedef T* iterator;
    typedef const T* const_iterator;

    /**
     * @brief Begin iterator.
     * @return An iterator to the first element.
     */
    iterator Begin() {
        // TODO: implement this function.
    }

    /**
     * @brief End iterator.
     * @return An iterator to one past the last element.
     */
    iterator End() {
        // TODO: implement this function.
    }

    /**
     * @brief Begin iterator.
     * @return A const iterator to the first element.
     */
    const_iterator Begin() const {
        // TODO: implement this function.
    }

    /**
     * @brief End iterator.
     * @return A const iterator to one past the last element.
     */
    const_iterator End() const {
        // TODO: implement this function.
    }

    /**
     * @brief Gets the number of elements that the container has currently allocated space for.
     * @return The number of elements that can be held in currently allocated storage.
     */
    std::size_t Capacity() const {
        // TODO: implement this function.
    }

    /**
     * @brief Gets the number of elements.
     * @return The number of elements in the container.
     */
    std::size_t Size() const {
        // TODO: implement this function.
    }

    /**
     * @brief Adds an element to the end.
     *        If there is no space to add an element, then the capacity of the vector is doubled..
     * @param elem The element to be added.
     */
    void Push_Back(T elem) {
        // TODO: implement this function.
    }

    /**
     * @brief Removes the last element of the container.
     *        The capacity of the vector is unchanged.
     *        If there are no elements in the container, then do nothing.
     */
    void Pop_Back() {
        // TODO: implement this function.
    }

    /**
     * @brief Increases the capacity of the container to a value greater or equal to new_cap.
     *        If new_cap is greater than the current capacity(), new storage is allocated,
     *        otherwise the method does nothing.
     * @param new_cap new capacity of the container.
     */
    void Reserve(std::size_t new_cap) {
        // TODO: implement this function.
    }

    /**
     * @brief Overloaded array subscripting operator.
     * @param pos The position of the element to access.
     * @return A reference to the element at specified location pos.
     *         No bounds checking is performed.
     */
    T &operator[](std::size_t pos) {
        // TODO: implement this function.
    }

    /**
     * @brief Const overload of the overloaded array subscripting operator.
     * @param pos The position of the element to access.
     * @return A const reference to the element at specified location pos.
     *         No bounds checking is performed.
     */
    const T &operator[](std::size_t pos) const {
        // TODO: implement this function.
    }

    /**
     * @brief Access specified element with bounds checking.
     * @param pos The position of the element to access.
     * @return A reference to the element at specified location pos, with bounds checking.
     * @throw std::out_of_range if pos >= size.
     */
    T &At(std::size_t pos) {
        // TODO: implement this function.
    }

    /**
     * @brief Access specified element with bounds checking.
     * @param pos The position of the element to access.
     * @return A const reference to the element at specified location pos, with bounds checking.
     * @throw std::out_of_range if pos >= size.
     */
    const T &At(std::size_t pos) const {
        // TODO: implement this function.
    }

    /**
     * @brief Checks whether the container is empty.
     * @return true if the container is empty, false otherwise.
     */
    bool Empty() const {
        // TODO: implement this function.
    }

    /**
     * @brief Removes all elements from the container.
     *        Leaves the capacity of the vector unchanged.
     */
    void Clear() {
        // TODO: implement this function.
    }

    /**
     * @brief Erases an element at pos.
     * @param pos Iterator to the element to remove.
     * @return Iterator following the last removed element.
     *         If the iterator pos refers to the last element, the end() iterator is returned.
     */
    iterator Erase(iterator pos) {
        // TODO: implement this function.
    }
};

#endif //A6_VECTOR_HPP
