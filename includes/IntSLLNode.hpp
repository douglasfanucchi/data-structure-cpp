#ifndef INT_SLL_NODE_H
# define INT_SLL_NODE_H

class IntSLLNode {
    public:
        IntSLLNode(int value, IntSLLNode *next = 0);

        int value;
        IntSLLNode *next;
};

#endif
