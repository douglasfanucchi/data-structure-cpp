#ifndef INT_SLLIST_H
# define INT_SLLIST_H

#include <IntSLLNode.hpp>

class IntSLList {
    private:
        IntSLLNode *head, *tail;

    public:
        IntSLList(void);
        bool isEmpty(void);
};

#endif
