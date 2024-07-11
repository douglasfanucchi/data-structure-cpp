#include <IntSLList.hpp>

IntSLList::IntSLList(void) : head(0), tail(0) {}

bool IntSLList::isEmpty(void) {
    return this->head == 0;
}

void IntSLList::addToHead(int value) {
    IntSLLNode *node = new IntSLLNode(value, this->head);

    if (this->isEmpty()) {
        this->tail = node;
    }
    this->head = node;
}
