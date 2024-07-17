#ifndef STACK_H
#define STACK_H

#include <DLList.hpp>

template<typename T>
class Stack : public DLList<T> {
    public:
        void push(const T&);
        T pop(void);
        const T &topEl(void) const;
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

#endif
