#ifndef GRAPH_MATRIX_H
# define GRAPH_MATRIX_H

class GraphMatrix {
    protected:
        int _edges;
        int _n;
        bool **_matrix;
        bool isValidVertex(int) const;

    public:
        GraphMatrix(int);
        bool hasEdges(void) const;
        int countVertices(void) const;
        int countEdges(void) const;
        virtual void insertEdge(int, int);
        void deleteEdge(int, int);
        bool edgeExists(int, int) const;
        bool hasAdjacent(int) const;
        int degree(int) const;
        ~GraphMatrix(void);
};

#endif
