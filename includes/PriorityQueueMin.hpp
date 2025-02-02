#ifndef PRIORITY_QUEUE_MIN
# define PRIORITY_QUEUE_MIN

#include <MinHeap.hpp>
#include <PriorityQueueItem.hpp>

template<typename T>
class PriorityQueueMin : public MinHeap<PriorityQueueItem<T>> {
    public:
        PriorityQueueMin(int);
        void enqueue(PriorityQueueItem<T>&);
        T dequeue(void);
    protected:
        void swapWithParentIfNeeded(int);
};

template<typename T>
PriorityQueueMin<T>::PriorityQueueMin(int n) : MinHeap<PriorityQueueItem<T>>(n) {}

template<typename T>
void PriorityQueueMin<T>::enqueue(PriorityQueueItem<T> &el) {
    this->insert(&el);
    el.index = this->_size - 1;
    this->swapWithParentIfNeeded(this->_size - 1);
}

template<typename T>
void PriorityQueueMin<T>::swapWithParentIfNeeded(int index) {
    if (index == 0) {
        return;
    }

    int parent = (index - 1) / 2;
    if (*this->_arr[parent] <= *this->_arr[index]) {
        return;
    }
    PriorityQueueItem<T> *tmp = this->_arr[parent];
    this->_arr[parent] = this->_arr[index];
    this->_arr[index] = tmp;
    this->_arr[parent]->index = parent;
    this->_arr[index]->index = index;
    this->swapWithParentIfNeeded(parent);
}

template<typename T>
T PriorityQueueMin<T>::dequeue(void) {
    if (this->isEmpty()) {
        throw "empty queue";
    }
    PriorityQueueItem<T> *queueItem = this->_arr[0];
    queueItem->index = -1;
    this->_arr[0] = this->_arr[this->_size - 1];
    this->_size--;
    this->maintenance(0);

    return queueItem->item;
}

#endif
