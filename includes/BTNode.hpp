#ifndef BT_NODE_H
# define BT_NODE_H

template<typename T>
class BTNode {
    public:
        T value;
        BTNode(void) : left(0), right(0) {}
        BTNode(const T &value, BTNode<T> *left = 0, BTNode<T> *right = 0);
        BTNode<T> *left, *right;
};

template<typename T>
BTNode<T>::BTNode(const T &value, BTNode<T> *left, BTNode<T> *right) : value(value), left(left), right(right) {}

#endif