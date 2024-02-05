//Jason Graham
//11/9/22
//Binary Tree Code

#ifndef BTREE_HPP
#define BTREE_HPP

#include <iostream>

template <typename T>
class btree {
    public:
    btree() : left(0), right(0), empty(true) {};
    btree(const T& item) : left(0), right(0), empty(false), data(item) {};
    ~btree();
    btree(const btree<T>&);
    void swap(btree<T>&);
    btree<T>& operator=(btree<t> rhs) { swap(rhs); return *this};

    bool isEmpty() const {return empty};
    bool isFull() const;
    void binsert(const T&);
    bool bfind(const T&) const;
    void inorder(std::ostream&) const;
    void preorder(std::ostream&) const;
    void postorder(std::ostream&) const;


    private:
    T data;
    bool empty;
    btree *left, *right;

};


// REQUIRES: !isFull()
// ENSURES: x is in BST
template <typename T>
void btree<T>::binsert(const T& x) {
    if(empty) {
        data = x;
        return;
    }

    if(x < data) {//Goes in left subtree
        if(left) //0 = false, all other numbers is true
            left->binstert(x);  //*(left).binsert(x)
        else
            left = new btree<T>(x);

    } else { // Goes in right subtree
        if(x == data) return; //prevents duplicates
        if(right)
            right->binsert(x);
        else
            right = new btree<T>(x);   
    }
}

template <typename T>
bool btree<T>::bfind(const T& key) const {
    if(empty) return false;
    if(key == data) return true;
    if(key < data){
        if(left) return left->bfind(key);
        else return false;
    } else {
        if(right) return right->bfind(key);
        else return false;
    }
}

template <typename T>
void btree<T>::inorder(std::ostream& out) const {
    if(empty) return;
    if(left) left->inorder(out);
    out << data;
    if(right) right->inorder(out);
}

template <typename T>
void btree<T>::preorder(std::ostream& out) const {
    if(empty) return;
    out << data;
    if(left) left->preorder(out);
    if(right) right->preorder(out);
}

template <typename T>
void btree<T>::postorder(std::ostream& out) const {
    if(empty) return;
    if(left) left->postorder(out);
    if(right) right->postorder(out);
    out << data;
}

template <typename T>
btree<T>::~btree() {
    if(left) delete left;   //Calls dtor on left
    if(right) delete right; //Calls dtor on right
    //Visit - compiler deallocates btree object
}

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree() {
    if(actual.empty) return;
    data = actual.data;
    empty = false;
    if(actual.left) left = new btree(*(actual.left));
    if(actual.right) right = new btree(*(actual.right));

}




#endif
