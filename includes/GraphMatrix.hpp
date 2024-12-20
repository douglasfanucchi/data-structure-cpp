#ifndef GRAPH_MATRIX_H
# define GRAPH_MATRIX_H

class GraphMatrix {
    protected:
        int _edges;
        int _n;
        bool **_matrix;

    public:
        GraphMatrix(int);
        bool hasEdges(void) const;
        int countVertices(void) const;
        int countEdges(void) const;
        void insertEdge(int, int);
        ~GraphMatrix(void);
};

#endif
