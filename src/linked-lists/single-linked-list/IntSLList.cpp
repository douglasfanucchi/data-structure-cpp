#include <IntSLList.hpp>

IntSLList::IntSLList(void) : head(0), tail(0) {}

IntSLList::~IntSLList(void) {
    while (this->head) {
        IntSLLNode *node = this->head;
        this->head = this->head->next;
        delete node;
    }
}

bool IntSLList::isEmpty(void) const {
    return this->head == 0;
}

void IntSLList::addToHead(int value) {
    IntSLLNode *node = new IntSLLNode(value, this->head);

    if (this->isEmpty()) {
        this->tail = node;
    }
    this->_current = this->head = node;
}

void IntSLList::addToTail(int value) {
    IntSLLNode *node = new IntSLLNode(value);

    if (this->isEmpty()) {
        this->_current = this->tail = this->head = node;
        return;
    }
    this->tail->next = node;
    this->tail = node;
}

void IntSLList::insertSort(int value) {
    if (this->isEmpty()) {
        this->addToHead(value);
        return;
    }
    if (!this->head->next && this->head->value >= value) {
        this->_current = this->head = new IntSLLNode(value, this->head);
        return;
    }
    IntSLLNode *trav = this->head;
    while(trav) {
        IntSLLNode *next = trav->next;
        if (next && next->value >= value) {
            break;
        }
        trav = next;
    }
    if (!trav) {
        this->addToTail(value);
        return;
    }
    trav->next = new IntSLLNode(value, trav->next);
}

int IntSLList::deleteFromHead(void) {
    IntSLLNode *node = this->head;
    this->_current = this->head = this->head->next;
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

int IntSLList::current(void) const {
    if (this->isEmpty()) {
        throw "empty list";
    }
    return this->_current->value;
}

bool IntSLList::next(void) {
    if (this->isEmpty()) {
        throw "empty list";
    }
    if (!this->_current) {
        return false;
    }
    this->_current = this->_current->next;
    return this->_current != nullptr;
}
