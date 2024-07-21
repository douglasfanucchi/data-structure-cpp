#ifndef DEQUE_H
# define DEQUE_H

template<typename T>
class Deque {
    protected:
        T *head;
        T *tail;
        T **blocks;
        T **blockHead;
        T **blockTail;
        int blockSize = 4;
    public:
        Deque(void);
        ~Deque(void);
        bool isEmpty(void) const;
        void pushFront(const T&);
        T popFront(void);
        T operator[](int) const;
};

template<typename T>
Deque<T>::Deque(void) : head(0), tail(0) {
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
        *this->blockHead = new T[3];
        (*this->blockHead)[1] = el;
        this->head = this->tail = (*this->blockHead) + 1;
        return;
    }
    int cellsBeforeHead = this->head - *this->blockHead;
    int positionBeforeHead = cellsBeforeHead - 1;
    if (cellsBeforeHead > 0) {
        (*this->blockHead)[positionBeforeHead] = el;
        this->head = (*this->blockHead) + positionBeforeHead;
        return;
    }
    this->blockHead -= 1;
    int availableBlocks = this->blockHead - this->blocks;
    if (availableBlocks == 0) {
        int size = this->blockSize * 2;
        T **blocks = new T*[size];
        for (int i = 0; i < this->blockSize; i++) {
            blocks[i] = 0;
            blocks[this->blockSize + i] = this->blocks[i];
        }
        delete[] this->blocks;
        this->blocks = blocks;
        this->blockHead = blocks + this->blockSize - 1;
        this->blockSize = size;
    }
    *this->blockHead = new T[3];
    (*this->blockHead)[2] = el;
    this->head = (*this->blockHead) + 2;
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

#endif