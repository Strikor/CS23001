#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <cassert>
#include <new>

template <typename T>
class node{
public: 
             node()              : next(0) {}; // default constructor
             node(const T& item) : data(item), next(0) {};
    T        data;
    node<T>* next;
private:
};

template <typename T>
class queue{
public:
                queue() : beginning(0), ending(0){};                  // default constructor
               ~queue();                                              // destructor
                queue     (const queue<T>&);                          // copy constructor
    void        swap      (queue<T>&);                                
    queue<T>&   operator= (queue<T> rhs) {swap(rhs); return *this;};

    bool        isEmpty   ()  const      {return beginning == 0;};
    bool        isFull    ()  const;
    T           dequeue   ();
    void        enqueue   (const T&);
private:
    node<T>    *beginning, *ending;
};


// REQUIRES: beginning-> x1 -> ... -> xn <- ending && !isFull()
// ENSURES: beginning-> x1 -> ... -> xn -> item <- ending
template <typename T>
void queue<T>::enqueue(const T& item){
    assert(!isFull());
    if (ending == 0) {
        ending = new node<T>(item);
        beginning = ending;
    } else{
        ending->next = new node<T>(item);
        ending = ending->next;
    }
}


// REQUIRES: !isEmpty()
template<typename T>
T queue<T>::dequeue(){
    assert(!isEmpty());
    T result = beginning->data;
    if (beginning == ending){
        delete beginning;
        ending = 0;
        beginning = 0;
    } else{
        node<T> *temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
    return result;
}


template<typename T>
queue<T>::~queue(){
    node<T> *temp;
    while(beginning != 0){
        temp = beginning;
        beginning = beginning->next;
        delete temp;
    }
}

template<typename T>
queue<t>::queue(const queue<T>& actual) : queue() /*setting ending and beginning to 0 by invoking the default constructor*/ {
    node<T> *temp = actual.beginning;
    while (temp != 0){
        if (beginning == 0){ // first node to be inserted
            beginning = new node<T>(temp->data);
            ending = beginning;
        } else{
            ending->next = new node<t>(temp->data);
            ending = ending->next;
        }
        temp = temp->next;
    }
}

template<typename T>
void queue<t>::swap(queue<t>& rhs){
    node<t> *temp = beginning;
    beginning     = rhs.beginning;
    rhs.beginning = temp;
    temp          = ending;
    ending        = rhs.ending;
    rhs.ending    = temp;
}

template<typename T>
bool queue<T>::isFull() const {
    node<T>* temp = new(std::nothrow) node<T>();
    if (temp == 0) return true;
    delete temp;
    return false;
}

#endif // QUEUE_HPP


