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
        delete this->blocks[i];
    }
    delete[] this->blocks;
}

template<typename T>
bool Deque<T>::isEmpty(void) const {
    return this->head == NULL;
}

#endif