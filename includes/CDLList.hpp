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
};

template<typename T>
CDLList<T>::CDLList(void) : tail(0) {}

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
    this->tail = new DLLNode<T>(value, this->tail, this->tail->next);
}

#endif
