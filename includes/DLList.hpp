#ifndef DLLIST_H
# define DLLIST_H

#include <DLLNode.hpp>

template <typename T>
class DLList {
    private:
        DLLNode<T> *head, *tail;
    public:
        DLList(void);
        bool isEmpty(void);
};

#endif

template<typename T>
DLList<T>::DLList(void) : head(0), tail(0) {}

template<typename T>
bool DLList<T>::isEmpty(void) {
    return this->head == 0;
}
