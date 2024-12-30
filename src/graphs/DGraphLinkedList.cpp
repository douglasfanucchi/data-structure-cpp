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
