#ifndef QUEUE_H
# define QUEUE_H

#include <DLList.hpp>

template<typename T>
class Queue : protected DLList<T> {
    public:
        bool isEmpty(void) const;
        void enqueue(const T&);
};

template<typename T>
bool Queue<T>::isEmpty(void) const {
    return this->head == 0;
}

#endif