#ifndef INT_SLLIST_H
# define INT_SLLIST_H

#include <IntSLLNode.hpp>

class IntSLList {
    private:
        IntSLLNode *head, *tail;

    public:
        IntSLList(void);
        ~IntSLList(void);
        bool isEmpty(void);
        void addToHead(int);
        void addToTail(int);
        int deleteFromHead(void);
        int deleteFromTail(void);
        void deleteNode(int);
};

#endif
