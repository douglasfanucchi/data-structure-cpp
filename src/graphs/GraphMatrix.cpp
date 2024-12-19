#include <GraphMatrix.hpp>

GraphMatrix::GraphMatrix(int n) : _n(n) {
    this->_edges = 0;
}

bool GraphMatrix::hasEdges(void) const {
    return this->_edges > 0;
}

int GraphMatrix::countVertices(void) const {
    return this->_n;
}
