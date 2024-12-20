#include <GraphMatrix.hpp>

GraphMatrix::GraphMatrix(int n) : _edges(0), _n(n) {
    this->_matrix = new bool*[n];
    for (int i = 0; i < n; i++) {
        this->_matrix[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            this->_matrix[i][j] = false;
        }
    }
}

bool GraphMatrix::hasEdges(void) const {
    return this->_edges > 0;
}

int GraphMatrix::countVertices(void) const {
    return this->_n;
}

int GraphMatrix::countEdges(void) const {
    return this->_edges;
}

void GraphMatrix::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (v0 == v1) {
        throw "invalid edge";
    }
    if (!this->_matrix[v0][v1]) {
        this->_edges++;
    }
    this->_matrix[v0][v1] = true;
    this->_matrix[v1][v0] = true;
}

void GraphMatrix::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = false;
    this->_matrix[v1][v0] = false;
    this->_edges--;
}

bool GraphMatrix::isValidVertex(int v) const {
    return (v >= 0 && v < this->_n);
}

bool GraphMatrix::edgeExists(int v0, int v1) const {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    return this->_matrix[v0][v1];
}

GraphMatrix::~GraphMatrix(void) {
    for (int i = 0; i < this->_edges; i++) {
        delete this->_matrix[i];
    }
    delete this->_matrix;
}
