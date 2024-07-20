#ifndef DEQUE_H
# define DEQUE_H

#include <DLLNode.hpp>

template<typename T>
class Deque {
    protected:
        DLLNode<T> *head;
        DLLNode<T> *tail;
        DLLNode<T> **blocks;
        DLLNode<T> **blockHead;
        DLLNode<T> **blockTail;
        int blockSize = 4;
    public:
        Deque(void);
        ~Deque(void);
        bool isEmpty(void) const;
};

template<typename T>
Deque<T>::Deque(void) : head(0), tail(0) {
    this->blocks = new DLLNode<T>*[this->blockSize];
    for(int i = 0; i < this->blockSize; i++)
        this->blocks[i] = NULL;
    this->blockHead = this->blockTail = this->blocks + 2;
}

template<typename T>
Deque<T>::~Deque(void) {
    for(int i = 0; i < this->blockSize; i++) {
        delete this->blocks[i];
    }
    delete[] this->blocks;
}

template<typename T>
bool Deque<T>::isEmpty(void) const {
    return this->head == NULL;
}

#endif