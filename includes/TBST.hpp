#ifndef TBST_H
# define TBST_H

#include <iostream>
#include <queue>

template<typename T>
class TBSTNode
{
    public:
        TBSTNode<T> *left;
        TBSTNode<T> *right;
        unsigned char successor;
        T value;
        TBSTNode(const T &value) : left(0), right(0), successor(1), value(value) {}
};

template<typename T>
class TBST
{
    protected:
        TBSTNode<T> *root;
    public:
        bool isEmpty(void) const;
        TBST(void) : root(0) {}
        void insert(const T&);
        std::queue<T> inorder(void) const;
        std::queue<T> preorder(void) const;
        ~TBST(void) {
            TBSTNode<T> *next;
            if (!this->root)
                return;
            for(;this->root->left; this->root = this->root->left);
            while(this->root) {
                next = this->root->right;
                if (!this->root->successor) {
                    for(;next->left; next = next->left);
                }
                delete this->root;
                this->root = next;
            }
        }
};

template<typename T>
bool TBST<T>::isEmpty(void) const {
    return this->root == NULL;
}

template<typename T>
void TBST<T>::insert(const T &value) {
    TBSTNode<T> *root = this->root;
    if (!root) {
        this->root = new TBSTNode<T>(value);
        return;
    }
    while (root) {
        if (value < root->value) {
            if (!root->left) {
                root->left = new TBSTNode<T>(value);
                root->left->right = root;
                break;
            }
            root = root->left;
            continue;
        }
        if (!root->successor) {
            root = root->right;
            continue;
        }
        TBSTNode<T> *node = new TBSTNode<T>(value);
        root->successor = 0;
        node->right = root->right;
        root->right = node;
        break;
    }
}

template<typename T>
std::queue<T> TBST<T>::inorder(void) const {
    std::queue<T> queue;
    TBSTNode<T> *node = this->root;

    for (;node->left; node = node->left);
    while (node) {
        queue.push(node->value);
        if (node->successor) {
            node = node->right;
            continue;
        }
        node = node->right;
        for(;node->left; node = node->left);
    }
    return queue;
}

template<typename T>
std::queue<T> TBST<T>::preorder(void) const {
    std::queue<T> queue;
    TBSTNode<T> *node = this->root;

    while(node) {
        while (node->left) {
            queue.push(node->value);
            node = node->left;
        }
        queue.push(node->value);
        while (node && node->successor) {
            node = node->right;
        }
        if(node){
            node = node->right;
        }
    }
    return queue;
}

#endif
