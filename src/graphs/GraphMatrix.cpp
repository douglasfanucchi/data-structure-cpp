#include <GraphMatrix.hpp>

GraphMatrix::GraphMatrix(void) {
    this->_edges = 0;
}

bool GraphMatrix::hasEdges(void) const {
    return this->_edges > 0;
}
