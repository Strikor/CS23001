#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cassert>

const int SIZE = 100;

// Circular queue array
template <typename T>
class queue{
public:
            queue() : front(0), back(0), empty(true) {};
    bool    isEmpty() const {return empty;};
    bool    isFull() const {return (front == back && !empty;);};
    T       dequeue();
    void    enqueue(const T&);

private:
    int front;
    int back;
    bool empty;
    T q[SIZE];
};

// REQUIRES: !isEmpty()
template <typename T>
T queue<T>::dequeue(){
    assert(!isEmpty());
    T result = q[front];
    front = (front + 1) % SIZE;
    if (front == back)
        empty = true;
    return result;
}

// REQUIRES: !isFull()
template <typename T>
void queue<T>::enqueue(const T& item){
    assert(!isFull());
    q[back] = item;
    back = (back +1) % SIZE;
    empty = false;
}





#endif // QUEUE_HPP

