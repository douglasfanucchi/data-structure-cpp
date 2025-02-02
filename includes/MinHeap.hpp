#ifndef HEAP_H
#define HEAP_H

#include <Deque.hpp>

template<typename T>
class MinHeap {
    protected:
        T **_arr;
        int _size;
        void maintenance(int);

    public:
        MinHeap(int);
        ~MinHeap(void);
        void insert(T*);
        T& operator[](int);
        bool isEmpty(void) const;
        void build(void);
};

template<typename T>
MinHeap<T>::MinHeap(int n) : _size(0) {
    this->_arr = new T*[n];
    
}

template<typename T>
MinHeap<T>::~MinHeap(void) {
    delete[] this->_arr;
}

template<typename T>
void MinHeap<T>::insert(T *el) {
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
    return *this->_arr[index];
}

template<typename T>
void MinHeap<T>::maintenance(int index) {
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (index > this->_size/2 - 1
        || (*this->_arr[index] <= *this->_arr[left] 
            && (right > this->_size - 1 || *this->_arr[index] <= *this->_arr[right]))
    ) {
        return;
    }

    int key = left;
    if (right < this->_size && *this->_arr[right] < *this->_arr[left]) {
        key = right;
    }

    T *tmp = this->_arr[index];
    this->_arr[index] = this->_arr[key];
    this->_arr[key] = tmp;
    this->maintenance(key);
}

#endif
