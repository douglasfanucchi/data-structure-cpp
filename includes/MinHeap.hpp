#ifndef HEAP_H
#define HEAP_H

#include <Deque.hpp>

template<typename T>
class MinHeap {
    protected:
        T *_arr;
        int _size;
        void maintenance(int);

    public:
        MinHeap(int);
        ~MinHeap(void);
        void insert(const T&);
        T& operator[](int);
        bool isEmpty(void) const;
        void build(void);
};

template<typename T>
MinHeap<T>::MinHeap(int n) : _size(0) {
    this->_arr = new T[n];
    
}

template<typename T>
MinHeap<T>::~MinHeap(void) {
    delete[] this->_arr;
}

template<typename T>
void MinHeap<T>::insert(const T& el) {
    this->_arr[this->_size] = el;
    this->_size++;
}

template<typename T>
void MinHeap<T>::build(void) {
    for (int i = this->_size/2 - 1; i >= 0; i--) {
        this->maintenance(i);
    }
}

template<typename T>
bool MinHeap<T>::isEmpty(void) const {
    return this->_size == 0;
}

template<typename T>
T& MinHeap<T>::operator[](int index) {
    return this->_arr[index];
}

template<typename T>
void MinHeap<T>::maintenance(int index) {
    int left = 2*index + 1;
    int right = 2*index + 2;
    int middleIndex = this->_size/2 - 1;

    if (index > middleIndex) {
        return;
    }
    int key = index;
    if (right > this->_size - 1) {
        if (this->_arr[index] > this->_arr[left]) {
            key = left;
        }
    } else if (this->_arr[index] > this->_arr[left] || this->_arr[index] > this->_arr[right]) {
        key = left;
        if (this->_arr[left] > this->_arr[right]) {
            key = right;
        }
    }
    if (key == index) {
        return;
    }
    T tmp = this->_arr[index];
    this->_arr[index] = this->_arr[key];
    this->_arr[key] = tmp;
    this->maintenance(key);
}

#endif
