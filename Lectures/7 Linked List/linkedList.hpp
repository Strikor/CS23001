#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <cassert>
#include <new>

template <typename T>
class node{
public: 
    node() : next(0) {}; // default constructor
    node(const T& item) : data(item), next(0) {};
    T data;
    node<T>* next;
private:
};

// CLASS INV: tos -> x1 -> x2 -> x3 -> x4 -> x5 -> xN -> 0
template <typename T>
class stack{
public: 
    stack() : tos(0) {}; // default constructor
    ~stack(); // destructor
    stack(const stack<T>&); // copy constructor
    void swap(stack<T>&); // constant time swap
    stack<T>& operator=(const stack<T>&);
    bool isEmpty() const {return tos == 0;};
    bool isFull() const;
    void push(const T&);
    T pop();
    T top() const;
private:
    node<T> *tos;
};

// REQUIRES: tos -> x1 -> x2 -> ... xN -> 0
// ENSURES: tos -> item -> x1 -> x2 -> ... xN -> 0
template <typename T>
void stack<T>::push(const T& item){
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos != 0 || tos -> x1 -> x2 -> ... xN -> 0
// ENSURES: tos -> x2 -> ... xN -> 0
template <typename T>
T stack<T>::pop(){
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
T stack<T>::top() const{
    assert(!isEmpty());
    T result = tos->data;
    return tos->data;
}

template <typename T>
stack<T>::~stack(){
    node<T> *temp;
    while(tos != 0){
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack(){
    node<T> *temp = actual.tos;
    node<T> *bottom;
    while(temp != 0){
        if (tos == 0){
            tos = new node<T>(temp->data);
            bottom = tos;
        } else{
            bottom->next = new node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }
}

template <typename T>
void stack<T>::swap(stack<T> &rhs){
    node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack<T> &rhs){
    swap(rhs);
    return *this;
}

template <typename T>
bool stack<T>::isFull() const{
    node<T> *temp = new(std::nothrow) node();
    if (temp == 0) return true; // out of memory
    delete temp;
    return false;
}


#endif // LINKEDLIST_HPP

