#include <DGraphLinkedList.hpp>

DGraphLinkedList::DGraphLinkedList(int n) : GraphLinkedList(n) {}

void DGraphLinkedList::insertEdge(int v0, int v1) {
    if (!this->isValidVertex(v0) || !this->isValidVertex(v1)) {
        throw "invalid vertex";
    }
    if (this->edgeExists(v0, v1)) {
        return;
    }
    this->_adjacents[v0]->addToHead(v1);
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
