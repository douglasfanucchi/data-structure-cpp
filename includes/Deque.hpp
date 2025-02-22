#ifndef DEQUE_H
# define DEQUE_H

#include <cstddef>

template<typename T>
class Deque {
    protected:
        T *head;
        T *tail;
        T **blocks;
        T **blockHead;
        T **blockTail;
        int blockSize;
        void increseBlocksSize(T**, int);
    public:
        Deque(void);
        ~Deque(void);
        bool isEmpty(void) const;
        void pushFront(const T&);
        void pushBack(const T&);
        T popFront(void);
        T popBack(void);
        T operator[](int) const;
};

template<typename T>
Deque<T>::Deque(void) : head(0), tail(0), blockSize(4) {
    this->blocks = new T*[this->blockSize];
    for(int i = 0; i < this->blockSize; i++)
        this->blocks[i] = NULL;
    this->blockHead = this->blockTail = this->blocks + 2;
}

template<typename T>
Deque<T>::~Deque(void) {
    for(int i = 0; i < this->blockSize; i++) {
        delete[] this->blocks[i];
    }
    delete[] this->blocks;
}

template<typename T>
bool Deque<T>::isEmpty(void) const {
    return this->head == NULL;
}

template<typename T>
void Deque<T>::pushFront(const T &el) {
    if (*this->blockHead == NULL) {
        *this->blockHead = *this->blockTail = new T[3];
        (*this->blockHead)[1] = el;
        this->head = this->tail = (*this->blockHead) + 1;
        return;
    }
    int cellsBeforeHead = this->head - *this->blockHead;
    if (cellsBeforeHead > 0) {
        this->head--;
        *this->head = el;
        return;
    }
    int headAvailableBlocks = this->blockHead - this->blocks;
    if (headAvailableBlocks == 0) {
        int tailAvailableBlocks = this->blocks + (this->blockSize - 1) - this->blockTail;
        int elementsSize = this->blockSize - tailAvailableBlocks;
        this->increseBlocksSize(this->blocks, elementsSize);
    }
    this->blockHead--;
    *this->blockHead = new T[3];
    this->head = *this->blockHead + 2;
    *this->head = el;
}

template<typename T>
T Deque<T>::popFront(void) {
    if (this->isEmpty()) {
        throw ("empty deque");
    }
    T value = *this->head;
    int cellsAvailable = this->head - *this->blockHead;
    if (cellsAvailable == 2 || this->head == this->tail) {
        delete[] *this->blockHead;
        *this->blockHead = NULL;
    }
    if (this->head == this->tail) {
        this->head = this->tail = NULL;
        return value;
    }
    if (cellsAvailable == 2) {
        this->blockHead++;
        this->head = *this->blockHead;
        return value;
    }
    this->head++;
    return value;
}

template<typename T>
T Deque<T>::operator[](int n) const {
    int headFilledCells = 3 - (this->head - *this->blockHead);
    if (n < headFilledCells) {
        return *(this->head + n);
    }
    n -= headFilledCells;
    int q = n / 3 + 1;
    int r = n % 3;
    if (this->blockHead + q > this->blockTail || this->head + r > this->tail){
        throw ("invalid index");
    }
    return *(*(this->blockHead + q) + r);
}

template<typename T>
void Deque<T>::pushBack(const T &value) {
    if (this->isEmpty()) {
        return this->pushFront(value);
    }
    int availableCells = *this->blockTail - this->tail + 2;
    if (availableCells > 0) {
        this->tail++;
        *this->tail = value;
        return;
    }
    int tailAvailableBlocks = this->blocks + (this->blockSize - 1) - this->blockTail;
    if (tailAvailableBlocks == 0) {
        int headAvailableBlocks = this->blockHead - this->blocks;
        T **elements = this->blocks + headAvailableBlocks;
        int elementsSize = this->blockSize - headAvailableBlocks;
        this->increseBlocksSize(elements, elementsSize);
    }
    this->blockTail++;
    *this->blockTail = this->tail = new T[3];
    *this->tail = value;
    return;
}

template<typename T>
T Deque<T>::popBack(void) {
    if (this->tail == this->head) {
        return this->popFront();
    }
    T value = *this->tail;
    if (*this->blockTail == this->tail) {
        delete[] *this->blockTail;
        *this->blockTail = NULL;
        this->blockTail--;
        this->tail = *this->blockTail + 2;
        return value;
    }
    this->tail--;
    return value;
}

template<typename T>
void Deque<T>::increseBlocksSize(T **elements, int elementsSize) {
    int size = this->blockSize * 2;
    int emptySpace = size - elementsSize;
    T **blocks = new T*[size];
    int halfEmptySpace = emptySpace / 2;
    for(int i = 0; i < halfEmptySpace; i++) {
        blocks[i] = 0;
        blocks[size - 1 - i] = 0;
    }
    if (emptySpace % 2 != 0) {
        blocks[size - 1 - halfEmptySpace] = 0;
    }
    for (int i = 0; i < elementsSize; i++) {
        blocks[halfEmptySpace + i] = elements[i];
    }
    delete[] this->blocks;
    this->blocks = blocks;
    this->blockHead = this->blocks + halfEmptySpace;
    this->blockTail = this->blockHead + elementsSize - 1;
    this->blockSize = size;
}

#endif