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
};

template<typename T>
CDLList<T>::CDLList(void) : tail(0) {}

template<typename T>
bool CDLList<T>::isEmpty(void) {
    return this->tail == 0;
}

#endif
