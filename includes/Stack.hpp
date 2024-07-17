#ifndef STACK_H
#define STACK_H

#include <DLList.hpp>

template<typename T>
class Stack : public DLList<T> {
    public:
        void push(const T&);
};

template<typename T>
void Stack<T>::push(const T &value) {
    this->addToHead(value);
}

#endif
