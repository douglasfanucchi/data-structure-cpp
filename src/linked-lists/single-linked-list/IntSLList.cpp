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

void IntSLList::deleteNode(int value) {
    if (this->isEmpty()) {
        throw ("empty list");
    }

    if (this->head == this->tail && this->head->value == value) {
        delete this->head;
        this->head = this->tail = 0;
        return;
    }

    if (this->head->value == value) {
        this->deleteFromHead();
        return;
    }

    if (this->tail->value == value) {
        this->deleteFromTail();
        return;
    }

    IntSLLNode *prev = this->head, *tmp = this->head->next;
    for(;tmp && tmp->value != value; prev = prev->next, tmp = tmp->next);
    if (!tmp) {
        return;
    }
    prev->next = tmp->next;

    delete tmp;
}

bool IntSLList::isInList(int value) {
    IntSLLNode *tmp;

    for(tmp = this->head; tmp && tmp->value != value; tmp = tmp->next);

    return tmp != 0;
}

int IntSLList::size(void) const {
    IntSLLNode *tmp;
    int result;

    for(tmp = this->head, result = 0; tmp; tmp = tmp->next, result++);

    return result;
}
