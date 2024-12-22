#include <PonderedGraphMatrix.hpp>

PonderedGraphMatrix::PonderedGraphMatrix(int n) : _n(n), _edges(0) {
    this->_matrix = new float*[n];
    for (int i = 0; i < n; i++) {
        this->_matrix[i] = new float[n];
        for (int j = 0; j < n; j++) {
            this->_matrix[i][j] = DEFAULT_VALUE;
        }
    }
}

int PonderedGraphMatrix::countEdges(void) const {
    return this->_edges;
}

void PonderedGraphMatrix::insertEdge(int v0, int v1, float value) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (DEFAULT_VALUE - this->_matrix[v0][v1] < 0.0001) {
        this->_edges++;
    }
    this->_matrix[v0][v1] = value;
    this->_matrix[v1][v0] = value;
}

bool PonderedGraphMatrix::isValidVertex(int v) const {
    return v > -1 && v < this->_n;
}

PonderedGraphMatrix::~PonderedGraphMatrix(void) {
    for (int i = 0; i < this->_n; i++) {
        delete this->_matrix[i];
    }
    delete this->_matrix;
}

void PonderedGraphMatrix::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = DEFAULT_VALUE;
    this->_matrix[v1][v0] = DEFAULT_VALUE;
    this->_edges--;
}
