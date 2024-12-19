#include <GraphMatrix.hpp>

GraphMatrix::GraphMatrix(int n) {
    this->_edges = 0;
}

bool GraphMatrix::hasEdges(void) const {
    return this->_edges > 0;
}
