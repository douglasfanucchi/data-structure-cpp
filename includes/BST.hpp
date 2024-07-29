#ifndef BST_H
# define BST_H

#include <BTNode.hpp>

template<typename T>
class BST {
    protected:
        BTNode<T> *root;

    public:
        BST(void) : root(0) {}
        bool isEmpty(void);
};

template<typename T>
bool BST<T>::isEmpty(void) {
    return this->root == 0;
}

#endif
