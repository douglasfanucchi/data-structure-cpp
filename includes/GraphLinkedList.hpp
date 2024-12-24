#ifndef GRAPH_LINKED_LIST_H
# define GRAPH_LINKED_LIST_H

#include <IntSLList.hpp>

class GraphLinkedList {
    public:
        GraphLinkedList(int);
        ~GraphLinkedList(void);
        int countEdges(void) const;
        void insertEdge(int, int);
        bool edgeExists(int, int) const;
        void deleteEdge(int, int);

    protected:
        int _edges;
        int _n;
        IntSLList **_adjacents;
        bool isValidVertex(int) const;
};

#endif