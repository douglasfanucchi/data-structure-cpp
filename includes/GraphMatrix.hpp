#ifndef GRAPH_MATRIX_H
# define GRAPH_MATRIX_H

#include <Deque.hpp>

class GraphMatrix {
    protected:
        int _edges;
        int _n;
        bool **_matrix;
        bool isValidVertex(int) const;
        void deepthFirstRecursive(int, Deque<int>&, int*) const;

    public:
        GraphMatrix(int);
        bool hasEdges(void) const;
        int countVertices(void) const;
        int countEdges(void) const;
        virtual void insertEdge(int, int);
        virtual void deleteEdge(int, int);
        bool edgeExists(int, int) const;
        bool hasAdjacent(int) const;
        virtual int degree(int) const;
        Deque<int> deepthFirst(int) const;
        ~GraphMatrix(void);
};

#endif
