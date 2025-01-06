#ifndef DGRAPH_LINKED_LIST_H
# define DGRAPH_LINKED_LIST_H

#include <GraphLinkedList.hpp>

class DGraphLinkedList : public GraphLinkedList {
    public:
        DGraphLinkedList(int);
        void insertEdge(int, int);
        void unsafeInsert(int, int);
        void deleteEdge(int, int);
        bool hasCycle(void) const;
        IntSLList topologicalSort(void) const;
        DGraphLinkedList transpose(void) const;
        IntSLList computeSCC(void) const;
        IntSLList *getAdjacents(int) const;
    protected:
        bool hasCycleRecursive(int, char*) const;
        void topologicalSortRecursive(IntSLList&, bool*, int) const;
        void computeSCCRecursive(IntSLList&, DGraphLinkedList*, bool*, int) const;
};

# endif
