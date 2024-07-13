#ifndef CDLLIST_H
# define CDLLIST_H

#include <DLLNode.hpp>

template<typename T>
class CDLList {
    private:
        DLLNode<T> *tail;

    public:
        CDLList(void);
        bool isEmpty(void);
        void addToTail(const T&);
        void addToHead(const T&);
        T deleteFromTail(void);
        ~CDLList(void);
};

template<typename T>
CDLList<T>::CDLList(void) : tail(0) {}

template<typename T>
CDLList<T>::~CDLList(void) {
    if (this->isEmpty()) {
        return;
    }
    DLLNode<T> *tmp, *node = this->tail->next;
    while (node) {
        tmp = node;
        node = node->next;
        if (tmp == this->tail) {
            node = 0;
        }
        delete tmp;
    }
}

template<typename T>
bool CDLList<T>::isEmpty(void) {
    return this->tail == 0;
}

template<typename T>
void CDLList<T>::addToTail(const T& value) {
    if (this->isEmpty()) {
        this->tail = new DLLNode<T>(value);
        this->tail->next = this->tail;
        this->tail->prev = this->tail;
        return;
    }
    this->tail = this->tail->next = new DLLNode<T>(value, this->tail, this->tail->next);
}

template<typename T>
void CDLList<T>::addToHead(const T &value) {
    if (this->isEmpty()) {
        return this->addToTail(value);
    }
    this->tail->next = new DLLNode<T>(value, this->tail, this->tail->next);
}

template<typename T>
T CDLList<T>::deleteFromTail(void) {
    if (this->isEmpty()) {
        throw ("empty list");
    }
    T value = this->tail->value;
    if (this->tail->next == this->tail) {
        delete this->tail;
        this->tail = 0;
        return value;
    }
    DLLNode<T> *tmp = this->tail;
    this->tail->prev->next = this->tail->next;
    this->tail->next->prev = this->tail->prev;
    this->tail = this->tail->prev;
    delete tmp;
    return value;
}

#endif
