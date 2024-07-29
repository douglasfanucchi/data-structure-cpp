#ifndef BT_NODE_H
# define BT_NODE_H

template<typename T>
class BTNode {
    public:
        T value;
        BTNode(void) : left(0), right(0) {}
        BTNode<T> *left, *right;
};

#endif