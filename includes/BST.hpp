#ifndef BST_H
# define BST_H

#include <BTNode.hpp>
#include <queue>

template<typename T>
class BST {
    protected:
        BTNode<T> *root;
        void insertRecursive(const T&, BTNode<T>*);
        void recursiveClear(BTNode<T>*);

    public:
        BST(void) : root(0) {}
        ~BST(void) { this->clear(); }
        bool isEmpty(void);
        void insert(const T&);
        T *search(const T&);
        std::queue<T> breadthFirst(void) const;
        void clear(void);
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
    this->insertRecursive(value, node->right);
}

template<typename T>
T *BST<T>::search(const T &value) {
    BTNode<T> *node = this->root;
    T *result = NULL;
    while (!result && node) {
        if (value == node->value) {
            result = &node->value;
        }
        if (value < node->value) {
            node = node->left;
            continue;
        }
        node = node->right;
    }
    return result;
}

template<typename T>
std::queue<T> BST<T>::breadthFirst(void) const {
    std::queue<T> result;
    std::queue<BTNode<T> *> queueNodes;
    BTNode<T> *node = this->root;
    while (node) {
        result.push(node->value);
        if (node->left) {
            queueNodes.push(node->left);
        }
        if (node->right) {
            queueNodes.push(node->right);
        }
        if (queueNodes.empty()) {
            break;
        }
        node = queueNodes.front();
        queueNodes.pop();
    }
    return result;
}

template<typename T>
void BST<T>::clear(void) {
    this->recursiveClear(this->root);
    this->root = 0;
}

template<typename T>
void BST<T>::recursiveClear(BTNode<T> *root) {
    if (!root) {
        return;
    }
    BTNode<T> *leftSubtree = root->left;
    BTNode<T> *rightSubtree = root->right;

    if (leftSubtree) {
        this->recursiveClear(leftSubtree);
    }
    if (rightSubtree) {
        this->recursiveClear(rightSubtree);
    }
    delete root;
}

#endif
