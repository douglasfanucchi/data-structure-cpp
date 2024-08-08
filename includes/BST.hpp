#ifndef BST_H
# define BST_H

#include <BTNode.hpp>
#include <queue>
#include <Stack.hpp>

template<typename T>
class BST {
    protected:
        BTNode<T> *root;
        void insertRecursive(const T&, BTNode<T>*);
        void recursiveClear(BTNode<T>*);
        void recursiveInorder(BTNode<T>*, std::queue<T>&) const;
        void recursivePreorder(BTNode<T>*, std::queue<T>&) const;
        void recursivePostorder(BTNode<T>*, std::queue<T>&) const;

    public:
        BST(void) : root(0) {}
        ~BST(void) { this->clear(); }
        bool isEmpty(void);
        void insert(const T&);
        T *search(const T&);
        std::queue<T> breadthFirst(void) const;
        std::queue<T> inorder(void) const;
        std::queue<T> preorder(void) const;
        std::queue<T> postorder(void) const;
        std::queue<T> noRecursivePreorder(void) const;
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
void BST<T>::recursiveInorder(BTNode<T> *node, std::queue<T> &result) const {
    if (!node) {
        return;
    }
    this->recursiveInorder(node->left, result);
    result.push(node->value);
    this->recursiveInorder(node->right, result);
}

template<typename T>
std::queue<T> BST<T>::inorder(void) const {
    std::queue<T> result;
    this->recursiveInorder(this->root, result);
    return result;
}

template<typename T>
std::queue<T> BST<T>::preorder(void) const {
    std::queue<T> result;
    this->recursivePreorder(this->root, result);
    return result;
}

template<typename T>
void BST<T>::recursivePreorder(BTNode<T> *node, std::queue<T> &result) const {
    if (!node) {
        return;
    }
    result.push(node->value);
    this->recursivePreorder(node->left, result);
    this->recursivePreorder(node->right, result);
}

template<typename T>
std::queue<T> BST<T>::postorder(void) const {
    std::queue<T> result;
    this->recursivePostorder(this->root, result);
    return result;
}

template<typename T>
void BST<T>::recursivePostorder(BTNode<T> *node, std::queue<T> &result) const {
    if (!node) {
        return;
    }
    this->recursivePostorder(node->left, result);
    this->recursivePostorder(node->right, result);
    result.push(node->value);
}

template<typename T>
std::queue<T> BST<T>::noRecursivePreorder(void) const {
    std::queue<T> queue;
    Stack<BTNode<T> *> stack;
    BTNode<T> *node = this->root;
    while (node) {
        queue.push(node->value);
        if (node->right) {
            stack.push(node->right);
        }
        if (node->left) {
            stack.push(node->left);
        }
        if (stack.isEmpty()) {
            node = NULL;
            continue;
        }
        node = stack.pop();
    }
    return queue;
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
