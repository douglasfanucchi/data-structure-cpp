#ifndef BST_H
# define BST_H

#include <BTNode.hpp>

template<typename T>
class BST {
    protected:
        BTNode<T> *root;
        void insertRecursive(const T&, BTNode<T>*);

    public:
        BST(void) : root(0) {}
        bool isEmpty(void);
        void insert(const T&);
};

template<typename T>
bool BST<T>::isEmpty(void) {
    return this->root == 0;
}

template<typename T>
void BST<T>::insert(const T &value) {
    if (this->isEmpty()) {
        this->root = new BTNode(value);
        return;
    }
    this->insertRecursive(value, this->root);
}

template<typename T>
void BST<T>::insertRecursive(const T &value, BTNode<T> *node) {
    if (value == node->value) {
        throw ("value already exists");
    }
    if (value < node->value) {
        if (node->left == NULL) {
            node->left = new BTNode<T>(value);
            return;
        }
        this->insertRecursive(value, node->left);
        return;
    }
    if (node->right == NULL) {
        node->right = new BTNode<T>(value);
        return;
    }
    this->insertRecursive(value, root->right);
}

#endif
