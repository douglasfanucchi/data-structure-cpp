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
    if (this->edgeExists(v0, v1)) {
        return;
    }
    this->_edges++;
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

void GraphLinkedList::deepthFirstRecursive(
    int v,
    Deque<int> &deque,
    char *colors,
    int* prevNodes,
    int *timeStart,
    int *timeEnd,
    int prevNode,
    int &time
) const {
    prevNodes[v] = prevNode;
    colors[v] = 1;
    time++;
    timeStart[v] = time;
    deque.pushBack(v);
    IntSLList *list = this->_adjacents[v];
    while (!list->isEmpty()) {
        int w = list->deleteFromHead();
        if (colors[w]) {
            continue;
        }
        this->deepthFirstRecursive(w, deque, colors, prevNodes, timeStart, timeEnd, v, time);
    }
    colors[v] = 2;
    time++;
    timeEnd[v] = time;
}

Deque<int> GraphLinkedList::deepthFirst(void) const {
    Deque<int> deque;

    char *colors = new char[this->_n];
    int *prevNodes = new int[this->_n];
    int *timeStart = new int[this->_n];
    int *timeEnd = new int[this->_n];
    int time = 0;

    for (int i = 0; i < this->_n; i++) {
        colors[i] = 0;
        prevNodes[i] = -1;
        timeStart[i] = -1;
        timeEnd[i] = -1;
    }
    for (int v = 0; v < this->_n; v++) {
        if (colors[v]) {
            continue;
        }
        this->deepthFirstRecursive(
            v,
            deque,
            colors,
            prevNodes,
            timeStart,
            timeEnd,
            -1,
            time
        );
    }

    delete[] colors;
    delete[] prevNodes;
    delete[] timeStart;
    delete[] timeEnd;
    return deque;
}

bool GraphLinkedList::hasCycleRecursive(int prev, int v, char *colors) const {
    IntSLList *list = this->_adjacents[v];
    colors[v] = 1;
    while (!list->isEmpty()) {
        int w = list->deleteFromHead();
        if ((colors[w] == 1 && prev != w) || this->hasCycleRecursive(v, w, colors)) {
            return true;
        }
    }
    return false;
}

bool GraphLinkedList::hasCycle(void) const {
    char *colors = new char[this->_n];
    bool result = false;
    for (int i = 0; i < this->_n; i++)
        colors[i] = 0;
    for (int i = 0; i < this->_n; i++) {
        if (colors[i] == 0) {
            result = this->hasCycleRecursive(-1, i, colors);
        }
    }
    delete[] colors;
    return result;
}

IntSLList GraphLinkedList::connectedComponents(void) const {
    IntSLList result;

    bool *visited = new bool[this->_n];
    for (int i = 0; i < this->_n; i++) {
        visited[i] = false;
    }

    int component = 1;
    for (int v = 0; v < this->_n; v++) {
        if (!visited[v]) {
            this->connectedComponentsRecursive(result, v, visited);
            result.addToTail(component++);
        }
    }

    delete[] visited;
    return result;
}

void GraphLinkedList::connectedComponentsRecursive(IntSLList &list, int v, bool *visited) const {
    IntSLList *adjacents = this->_adjacents[v];
    visited[v] = true;

    if (adjacents->isEmpty()) {
        return;
    }
    do {
        int w = adjacents->current();
        if (!visited[w]) {
            this->connectedComponentsRecursive(list, w, visited);
        }
    } while(adjacents->next());
}
