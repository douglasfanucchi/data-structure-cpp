#include <DGraphMatrix.hpp>

DGraphMatrix::DGraphMatrix(int n) : GraphMatrix(n) {}

void DGraphMatrix::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = true;
    this->_edges++;
}

void DGraphMatrix::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = false;
    this->_edges--;
}

int DGraphMatrix::degree(int v) const {
    if (!this->isValidVertex(v)) {
        throw "invalid vertex";
    }
    int total = 0;
    for (int i = 0; i < this->_n; i++) {
        if (this->_matrix[v][i]) {
            total++;
        }
        if (this->_matrix[i][v]) {
            total++;
        }
    }
    return total;
}
