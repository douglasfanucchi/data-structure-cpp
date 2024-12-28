#ifndef GRAPH_LINKED_LIST_H
# define GRAPH_LINKED_LIST_H

#include <IntSLList.hpp>
#include <Deque.hpp>

class GraphLinkedList {
    public:
        GraphLinkedList(int);
        ~GraphLinkedList(void);
        int countEdges(void) const;
        void insertEdge(int, int);
        bool edgeExists(int, int) const;
        void deleteEdge(int, int);
        int degree(int) const;
        Deque<int> deepthFirst(void) const;

    protected:
        int _edges;
        int _n;
        IntSLList **_adjacents;
        bool isValidVertex(int) const;
        void deepthFirstRecursive(int, Deque<int>&, bool*) const;
};

#endif