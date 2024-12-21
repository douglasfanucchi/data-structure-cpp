#ifndef DGRAPH_MATRIX_H
# define DGRAPH_MATRIX_H

#include <GraphMatrix.hpp>

class DGraphMatrix : public GraphMatrix {
    public:
        DGraphMatrix(int);
        void insertEdge(int, int);
};

#endif
