#ifndef STACK_H
#define STACK_H

#include <DLList.hpp>

template<typename T>
class Stack : public DLList<T> {
    public:
        void push(const T&);
};

#endif
