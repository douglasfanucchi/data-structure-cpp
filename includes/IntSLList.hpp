#ifndef INT_SLLIST_H
# define INT_SLLIST_H

#include <IntSLLNode.hpp>

class IntSLList {
    private:
        IntSLLNode *head, *tail, *_current;

    public:
        IntSLList(void);
        ~IntSLList(void);
        bool isEmpty(void) const;
        void addToHead(int);
        void addToTail(int);
        void insertSort(int);
        int deleteFromHead(void);
        int deleteFromTail(void);
        void deleteNode(int);
        bool isInList(int);
        int size(void) const;
        int current(void) const;
        bool next(void);
};

#endif
