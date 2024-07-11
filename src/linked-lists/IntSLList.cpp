#include <IntSLList.hpp>

IntSLList::IntSLList(void) : head(0), tail(0) {}

bool IntSLList::isEmpty(void) {
    return this->head == 0;
}
