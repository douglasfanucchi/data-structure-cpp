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
        T deleteFromTail(void);
        T deleteFromHead(void);
        void deleteNode(const T&);
        bool isInList(const T&);
};

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
    DLLNode<T> *node = new DLLNode<T>(value, NULL, this->head);
    if (this->isEmpty()) {
        this->head = this->tail = node;
        return;
    }
    this->head->prev = node;
    this->head = node;
}

template<typename T>
void DLList<T>::addToTail(const T& value) {
    DLLNode<T> *node = new DLLNode<T>(value, this->tail);
    if (this->isEmpty()) {
        this->tail = this->head = node;
        return;
    }
    this->tail->next = node;
    this->tail = node;
}

template <typename T>
T DLList<T>::deleteFromTail(void) {
    if (this->isEmpty()) {
        throw ("empty list");
    }
    T value = this->tail->value;
    if (this->head == this->tail) {
        delete this->tail;
        this->tail = this->head = 0;
        return value;
    }
    this->tail = this->tail->prev;
    delete this->tail->next;
    this->tail->next = 0;
    return value;
}

template<typename T>
T DLList<T>::deleteFromHead(void) {
    if (this->isEmpty()) {
        throw ("empty list");
    }
    T value = this->head->value;
    if (this->head == this->tail) {
        delete this->head;
        this->head = this->tail = 0;
        return value;
    }
    this->head = this->head->next;
    delete this->head->prev;
    this->head->prev = 0;
    return value;
}

template<typename T>
void DLList<T>::deleteNode(const T& value) {
    DLLNode<T> *tmp;
    if (this->head == this->tail && this->head->value == value) {
        delete this->head;
        this->head = this->tail = 0;
    }
    for (tmp = this->head; tmp && tmp->value != value; tmp = tmp->next);
    if (!tmp) {
        return;
    }
    if (tmp == this->head) {
        this->head = this->head->next;
        this->head->prev = 0;
        delete tmp;
        return;
    }
    if (tmp == this->tail) {
        this->tail = this->tail->prev;
        this->tail->next = 0;
        delete tmp;
        return;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
}

template<typename T>
bool DLList<T>::isInList(const T& value) {
    DLLNode<T> *tmp;
    for(tmp = this->head; tmp && tmp->value != value; tmp = tmp->next);
    return tmp != 0;
}

#endif
