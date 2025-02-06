#include <PonderedGraphMatrix.hpp>
#include <PriorityQueueMin.hpp>

PonderedGraphMatrix::PonderedGraphMatrix(int n) : _n(n), _edges(0), _cost(0) {
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
        delete[] this->_matrix[i];
    }
    delete[] this->_matrix;
}

void PonderedGraphMatrix::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    this->_matrix[v0][v1] = DEFAULT_VALUE;
    this->_matrix[v1][v0] = DEFAULT_VALUE;
    this->_edges--;
}

bool PonderedGraphMatrix::edgeExists(int v0, int v1) const {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    return DEFAULT_VALUE - this->_matrix[v0][v1] > 0.0001;
}

bool PonderedGraphMatrix::hasAdjacent(int v) const {
    for (int i = 0; i < this->_n; i++) {
        if (this->edgeExists(v, i)) {
            return true;
        }
    }
    return false;
}

float PonderedGraphMatrix::getCost(void) const {
    return this->_cost;
}

void PonderedGraphMatrix::setCost(float cost) {
    this->_cost = cost;
}

PonderedGraphMatrix PonderedGraphMatrix::mst(void) {
    PonderedGraphMatrix result(this->_n);
    PriorityQueueMin<int> queue(this->_n);
    PriorityQueueItem<int> *items[this->_n];
    bool *visited = new bool[this->_n];
    int *prev = new int[this->_n];
    float cost = 0;

    int v = 0;
    for (int w = 0; w < this->_n; w++) {
        items[w] = nullptr;
        visited[w] = false;
        prev[w] = -1;
        if (this->edgeExists(v, w)) {
            items[w] = new PriorityQueueItem<int>(
                this->_matrix[v][w],
                w
            );
            prev[w] = 0;
            queue.enqueue(*items[w]);
        }
    }
    visited[0] = true;

    while(!queue.isEmpty()) {
        PriorityQueueItem<int> *el = queue.dequeue();
        int w = el->item;
        int v = prev[w];
        result.insertEdge(v, w, this->_matrix[v][w]);
        cost += this->_matrix[v][w];
        v = w;
        for (int w = 0; w < this->_n; w++) {
            if (!this->edgeExists(v, w) || visited[w]) {
                continue;
            }
            float weight = this->_matrix[v][w];
            if (!items[w]) {
                items[w] = new PriorityQueueItem<int>(
                    weight,
                    w
                );
                queue.enqueue(*items[w]);
                prev[w] = v;
                continue;
            }
            if (items[w]->priority > weight) {
                queue.decreasePriority(*items[w], weight);
                prev[w] = v;
            }
        }
        visited[v] = true;
        delete el;
    }
    result.setCost(cost);

    delete[] visited;
    delete[] prev;
    return result;
}

int PonderedGraphMatrix::degree(int v) const {
    int total = 0;
    for (int i = 0; i < this->_n; i++) {
        if (this->edgeExists(v, i)) {
            total++;
        }
    }
    return total;
}
