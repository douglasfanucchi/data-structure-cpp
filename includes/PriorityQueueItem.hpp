#ifndef PRIORITY_QUEUE_ITEM_H
# define PRIORITY_QUEUE_ITEM_H

template<typename T>
class PriorityQueueItem {
    public:
        int priority;
        int index;
        T item;

        PriorityQueueItem(void);
        PriorityQueueItem(int, const T&);
        bool operator<(const PriorityQueueItem<T>) const;
        bool operator<=(const PriorityQueueItem<T>) const;
        bool operator>(const PriorityQueueItem<T>) const;
        bool operator>=(const PriorityQueueItem<T>) const;
};

template<typename T>
PriorityQueueItem<T>::PriorityQueueItem(void) {}

template<typename T>
PriorityQueueItem<T>::PriorityQueueItem(int priority, const T& item) : priority(priority), item(item), index(-1) {}

template<typename T>
bool PriorityQueueItem<T>::operator<(const PriorityQueueItem<T> rhs) const {
    return this->priority < rhs.priority;
}

template<typename T>
bool PriorityQueueItem<T>::operator<=(const PriorityQueueItem<T> rhs) const {
    return this->priority <= rhs.priority;
}

template<typename T>
bool PriorityQueueItem<T>::operator>(const PriorityQueueItem<T> rhs) const {
    return this->priority > rhs.priority;
}

template<typename T>
bool PriorityQueueItem<T>::operator>=(const PriorityQueueItem<T> rhs) const {
    return this->priority >= rhs.priority;
}

#endif
