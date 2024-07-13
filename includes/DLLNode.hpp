#ifndef DLL_NODE_H
# define DLL_NODE_H

#include <cstddef>

template<typename T>
class DLLNode {
    public:
        DLLNode(const T& value, DLLNode *prev = NULL, DLLNode *next = NULL);
        T value;
        DLLNode *next;
        DLLNode *prev;
};

template<typename T>
DLLNode<T>::DLLNode(const T &value, DLLNode *prev, DLLNode *next) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

#endif
