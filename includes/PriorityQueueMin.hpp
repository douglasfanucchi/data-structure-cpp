#ifndef PRIORITY_QUEUE_MIN
# define PRIORITY_QUEUE_MIN

#include <MinHeap.hpp>
#include <PriorityQueueItem.hpp>

template<typename T>
class PriorityQueueMin : public MinHeap<PriorityQueueItem<T>> {
    public:
        PriorityQueueMin(int);
        void enqueue(int, const T&);
        T dequeue(void);
};

template<typename T>
PriorityQueueMin<T>::PriorityQueueMin(int n) : MinHeap<PriorityQueueItem<T>>(n) {}

template<typename T>
void PriorityQueueMin<T>::enqueue(int priority, const T& item) {
    PriorityQueueItem<T> queueItem(priority, item);
    this->insert(queueItem);
    this->build();
}

template<typename T>
T PriorityQueueMin<T>::dequeue(void) {
    if (this->isEmpty()) {
        throw "empty queue";
    }
    PriorityQueueItem<T> queueItem = this->_arr[0];
    this->_arr[0] = this->_arr[this->_size - 1];
    this->_size--;
    this->maintenance(0);

    return queueItem.item;
}

#endif
