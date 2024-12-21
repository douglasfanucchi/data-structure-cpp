#include <DGraphMatrix.hpp>

DGraphMatrix::DGraphMatrix(int n) : GraphMatrix(n) {}

void DGraphMatrix::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = true;
    this->_edges++;
}
