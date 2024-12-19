#ifndef GRAPH_MATRIX_H
# define GRAPH_MATRIX_H

class GraphMatrix {
    protected:
        int _edges;

    public:
        GraphMatrix(int);
        bool hasEdges(void) const;
};

#endif
