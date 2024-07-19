#ifndef QUEUE_H
# define QUEUE_H

#include <DLList.hpp>
#include <DLLNode.hpp>

template<typename T>
class Queue : protected DLList<T> {
    public:
        bool isEmpty(void) const;
        void enqueue(const T&);
        T dequeue(void);
        T firstEl(void) const;
        void clear(void);
};

template<typename T>
bool Queue<T>::isEmpty(void) const {
    return this->head == 0;
}

template<typename T>
void Queue<T>::enqueue(const T &el) {
    this->addToTail(el);
}

template<typename T>
T Queue<T>::dequeue(void) {
    if (this->isEmpty()) {
        throw ("empty queue");
    }
    return this->deleteFromHead();
}

template<typename T>
T Queue<T>::firstEl(void) const {
    if (this->isEmpty()) {
        throw ("empty queue");
    }
    return this->head->value;
}

template<typename T>
void Queue<T>::clear(void) {
    DLLNode<T> *tmp;
    while (this->head) {
        tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
}

#endif