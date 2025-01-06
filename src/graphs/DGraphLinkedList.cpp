#include <DGraphLinkedList.hpp>

DGraphLinkedList::DGraphLinkedList(int n) : GraphLinkedList(n) {}

void DGraphLinkedList::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (this->edgeExists(v0, v1)) {
        return;
    }
    this->_adjacents[v0]->insertSort(v1);
    this->_edges++;
}

void DGraphLinkedList::deleteEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (!this->edgeExists(v0, v1)) {
        return;
    }
    this->_adjacents[v0]->deleteNode(v1);
    this->_edges--;
}

bool DGraphLinkedList::hasCycle(void) const {
    if (this->countEdges() == 0) {
        return false;
    }
    char *colors = new char[this->_n];
    for (int i = 0; i < this->_n; i++)
        colors[i] = 0;

    bool result = false;
    for (int i = 0; i < this->_n; i++) {
        if (colors[i] != 0) {
            continue;
        }
        if (this->hasCycleRecursive(i, colors)) {
            result = true;
            break;
        }
    }
    delete[] colors;
    return result;
}

bool DGraphLinkedList::hasCycleRecursive(int v, char *colors) const {
    colors[v] = 1;
    IntSLList *list = this->_adjacents[v];
    while (!list->isEmpty()) {
        int w = list->deleteFromHead();
        if (colors[w] == 1 || this->hasCycleRecursive(w, colors)) {
            colors[v] = 2;
            return true;
        }
    }
    colors[v] = 2;
    return false;
}

IntSLList DGraphLinkedList::topologicalSort(void) const {
    IntSLList result;
    if (this->countEdges() == 0) {
        return result;
    }
    bool *visited = new bool[this->_n];
    for (int v = 0; v < this->_n; v++) {
        visited[v] = false;
    }
    for (int v = 0; v < this->_n; v++) {
        if (visited[v]) {
            continue;
        }
        this->topologicalSortRecursive(result, visited, v);
    }
    delete[] visited;
    return result;
}

void DGraphLinkedList::topologicalSortRecursive(IntSLList &list, bool *visited, int v) const {
    visited[v] = true;
    IntSLList *adjacents = this->_adjacents[v];
    if (adjacents->isEmpty()) {
        list.addToHead(v);
        return;
    }
    do
    {
        int w = adjacents->current();
        if (!visited[w]) {
            this->topologicalSortRecursive(list, visited, w);
        }
    } while (adjacents->next());
    list.addToHead(v);
}

void DGraphLinkedList::unsafeInsert(int v, int w) {
    this->_adjacents[v]->addToHead(w);
    this->_edges++;
}

DGraphLinkedList DGraphLinkedList::transpose(void) const {
    DGraphLinkedList result(this->_n);
    if (this->countEdges() == 0) {
        return result;
    }

    for (int v = this->_n - 1; v >= 0; v--) {
        IntSLList *adjacents = this->_adjacents[v];
        if (adjacents->isEmpty()) {
            continue;
        }
        do {
            int w = adjacents->current();
            result.unsafeInsert(w, v);
        } while(adjacents->next());
        adjacents->rewind();
    }

    return result;
}

IntSLList *DGraphLinkedList::getAdjacents(int v) const {
    if (!this->isValidVertex(v)) {
        throw "invalid vertex";
    }
    return this->_adjacents[v];
}

void DGraphLinkedList::computeSCCRecursive(IntSLList &result, DGraphLinkedList *transposed, bool *visited, int v) const {
    visited[v] = true;
    IntSLList *adjacents = transposed->getAdjacents(v);
    if (adjacents->isEmpty()) {
        return;
    }
    do {
        int w = adjacents->current();
        if (!visited[w])
            this->computeSCCRecursive(result, transposed, visited, w);
    } while(adjacents->next());
}

IntSLList DGraphLinkedList::computeSCC(void) const {
    IntSLList result;
    DGraphLinkedList transposed = this->transpose();
    bool *visited = new bool[this->_n];
    int component = 1;
    for (int v = 0; v < this->_n; v++)
        visited[v] = false;
    IntSLList topologicalOrdered = this->topologicalSort();
    do
    {
        int v = topologicalOrdered.current();
        if (!visited[v]) {
            this->computeSCCRecursive(result, &transposed, visited, v);
            result.addToTail(component++);
        }
    } while (topologicalOrdered.next());

    delete[] visited;
    return result;
}
