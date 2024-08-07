#ifndef STACK_H
#define STACK_H

#include <DLList.hpp>

template<typename T>
class Stack : protected DLList<T> {
    public:
        void push(const T&);
        T pop(void);
        const T &topEl(void) const;
        void clear(void);
        bool isEmpty(void) const;
};

template<typename T>
void Stack<T>::push(const T &value) {
    this->addToHead(value);
}

template<typename T>
T Stack<T>::pop(void) {
    if (this->isEmpty()) {
        throw ("empty stack");
    }
    return this->deleteFromHead();
}

template<typename T>
const T& Stack<T>::topEl(void) const {
    if (this->isEmpty()) {
        throw ("empty stack");
    }
    return this->head->value;
}

template<typename T>
void Stack<T>::clear(void) {
    DLLNode<T> *tmp;
    while (!this->isEmpty()) {
        tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
}

template<typename T>
bool Stack<T>::isEmpty(void) const {
    return this->head == 0;
}

#endif
