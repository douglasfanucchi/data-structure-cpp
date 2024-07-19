#ifndef QUEUE_H
# define QUEUE_H

#include <DLList.hpp>

template<typename T>
class Queue : protected DLList<T> {
    public:
        bool isEmpty(void) const;
};

#endif