#include <GraphMatrix.hpp>

GraphMatrix::GraphMatrix(int n) : _edges(0), _n(n) {}

bool GraphMatrix::hasEdges(void) const {
    return this->_edges > 0;
}

int GraphMatrix::countVertices(void) const {
    return this->_n;
}

int GraphMatrix::countEdges(void) const {
    return this->_edges;
}
