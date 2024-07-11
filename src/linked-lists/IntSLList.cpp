#include <IntSLList.hpp>

IntSLList::IntSLList(void) : head(0), tail(0) {}

IntSLList::~IntSLList(void) {
    while (this->head) {
        IntSLLNode *node = this->head;
        this->head = this->head->next;
        delete node;
    }
}

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

void IntSLList::addToTail(int value) {
    IntSLLNode *node = new IntSLLNode(value);

    if (this->isEmpty()) {
        this->tail = this->head = node;
        return;
    }
    this->tail->next = node;
    this->tail = node;
}

int IntSLList::deleteFromHead(void) {
    IntSLLNode *node = this->head;
    this->head = this->head->next;
    int value = node->value;

    delete node;
    return value;
}

int IntSLList::deleteFromTail(void) {
    int value = this->tail->value;

    if (this->head == this->tail) {
        delete this->tail;
        this->tail = this->head = 0;

        return value;
    }

    IntSLLNode *tmp = this->head;
    for (;tmp->next != this->tail; tmp = tmp->next);

    delete this->tail;
    tmp->next = 0;
    this->tail = tmp;

    return value;
}
