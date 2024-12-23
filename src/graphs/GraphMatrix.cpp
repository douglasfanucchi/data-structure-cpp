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

bool GraphMatrix::hasAdjacent(int v) const {
    if (!this->isValidVertex(v)) {
        throw "invalid vertex";
    }
    for (int i = 0; i < this->_n; i++) {
        if(this->_matrix[v][i]) {
            return true;
        }
    }
    return false;
}

int GraphMatrix::degree(int v) const {
    if (!this->isValidVertex(v)) {
        throw "invalid vertex";
    }
    int count = 0;
    for (int i = 0; i < this->_n; i++) {
        if (this->_matrix[v][i]) {
            count++;
        }
    }
    return count;
}

Deque<int> GraphMatrix::deepthFirst(int v) const {
    int *visited = new int[this->_n];
    Deque<int> deque;

    for (int i = 0; i < this->_n; i++) {
        if (!visited[i]) {
            this->deepthFirstRecursive(i, deque, visited);
        }
    }

    delete[] visited;
    return deque;
}

void GraphMatrix::deepthFirstRecursive(int v, Deque<int> &deque, int *visited) const {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    deque.pushBack(v);
    for (int i = 0; i < this->_n; i++) {
        if (this->edgeExists(v, i)) {
            this->deepthFirstRecursive(i, deque, visited);
        }
    }
}

GraphMatrix::~GraphMatrix(void) {
    for (int i = 0; i < this->_edges; i++) {
        delete this->_matrix[i];
    }
    delete this->_matrix;
}
