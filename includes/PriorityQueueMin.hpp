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
        void dequeue(PriorityQueueItem<T>&);
    protected:
        void swapWithParentIfNeeded(int);
        void swap(int, int);
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
    this->swap(index, parent);
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

template<typename T>
void PriorityQueueMin<T>::dequeue(PriorityQueueItem<T> &el) {
    if (this->isEmpty()) {
        throw "empty queue";
    }
    int index = el.index;
    if (index == -1 || this->_arr[index]->item != el.item) {
        throw "element not present";
    }
    this->_arr[this->_size - 1]->index = index;
    this->_arr[index] = this->_arr[this->_size - 1];
    el.index = -1;
    this->_size--;
    this->maintenance(index);
}

template<typename T>
void PriorityQueueMin<T>::swap(int i, int j) {
    this->_arr[i]->index = j;
    this->_arr[j]->index = i;
    this->MinHeap<PriorityQueueItem<T>>::swap(i, j);
}

#endif
