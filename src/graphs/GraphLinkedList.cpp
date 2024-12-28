#include <GraphLinkedList.hpp>

GraphLinkedList::GraphLinkedList(int n) : _n(n), _edges(0) {
    this->_adjacents = new IntSLList*[n];
    for (int i = 0; i < n; i++) {
        this->_adjacents[i] = new IntSLList;
    }
}

GraphLinkedList::~GraphLinkedList(void) {
    for (int i = 0; i < this->_n; i++) {
        delete this->_adjacents[i];
    }
    delete[] this->_adjacents;
}

int GraphLinkedList::countEdges(void) const {
    return this->_edges;
}

bool GraphLinkedList::edgeExists(int v0, int v1) const {
    return this->_adjacents[v0]->isInList(v1);
}

void GraphLinkedList::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (!this->edgeExists(v0, v1)) {
        this->_edges++;
    }
    this->_adjacents[v0]->addToTail(v1);
    this->_adjacents[v1]->addToTail(v0);
}

void GraphLinkedList::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (!this->edgeExists(v0, v1)) {
        return;
    }
    this->_edges--;
    this->_adjacents[v0]->deleteNode(v1);
    this->_adjacents[v1]->deleteNode(v0);
}

bool GraphLinkedList::isValidVertex(int v) const {
    return v > -1 && v < this->_n;
}

int GraphLinkedList::degree(int v) const {
    return this->_adjacents[v]->size();
}

void GraphLinkedList::deepthFirstRecursive(int v, Deque<int> &deque, bool *visited) const {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    deque.pushBack(v);
    IntSLList *list = this->_adjacents[v];
    while (!list->isEmpty()) {
        int v = list->deleteFromHead();
        this->deepthFirstRecursive(v, deque, visited);
    }
}

Deque<int> GraphLinkedList::deepthFirst(void) const {
    Deque<int> deque;

    bool *visited = new bool[this->_n];
    for (int i = 0; i < this->_n; i++) {
        visited[i] = false;
    }
    for (int v = 0; v < this->_n; v++) {
        if (visited[v]) {
            continue;
        }
        this->deepthFirstRecursive(v, deque, visited);
    }

    delete[] visited;
    return deque;
}
