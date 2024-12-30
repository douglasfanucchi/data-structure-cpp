#ifndef DGRAPH_LINKED_LIST_H
# define DGRAPH_LINKED_LIST_H

#include <GraphLinkedList.hpp>

class DGraphLinkedList : public GraphLinkedList {
    public:
        DGraphLinkedList(int);
        void insertEdge(int, int);
        void deleteEdge(int, int);
        bool hasCycle(void) const;
    protected:
        bool hasCycleRecursive(int, char*) const;
};

# endif
