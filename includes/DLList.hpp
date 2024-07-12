#ifndef DLLIST_H
# define DLLIST_H

#include <DLLNode.hpp>

template <typename T>
class DLList {
    private:
        DLLNode<T> *head, *tail;
    public:
        DLList(void);
        ~DLList(void);
        bool isEmpty(void);
        void addToHead(const T&);
        void addToTail(const T&);
};

#endif

template<typename T>
DLList<T>::DLList(void) : head(0), tail(0) {}

template <typename T>
DLList<T>::~DLList(void) {
    DLLNode<T> *node;

    while (this->head) {
        node = this->head;
        this->head = this->head->next;
        delete node;
    }
}

template<typename T>
bool DLList<T>::isEmpty(void) {
    return this->head == 0;
}

template<typename T>
void DLList<T>::addToHead(const T& value) {
    DLLNode<T> *node = new DLLNode<T>(value);
    if (this->isEmpty()) {
        this->head = this->tail = node;
        return;
    }
    this->head->prev = node;
    node->next = this->head;
    this->head = node;
}

template<typename T>
void DLList<T>::addToTail(const T& value) {
    DLLNode<T> *node = new DLLNode<T>(value);
    if (this->isEmpty()) {
        this->tail = this->head = node;
        return;
    }
    this->tail->next = node;
    node->prev = this->tail;
    this->tail = node;
}
