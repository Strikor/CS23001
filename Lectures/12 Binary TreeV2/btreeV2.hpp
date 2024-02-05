//Jason Graham
//11/14/2022
//btree implimentation

#include <iostream>

template <typename T>
class btree {
public:
    btree() : root(0) {};
    ~btree();
    btree(const btree<T>&);
    void swap(btree<T>&);
    btree<T>& operator=(btree<T> rhs) { swap(rhs); return *this; };

    bool isEmpty() const { return root == 0; };
    bool isFull() const;
    bool bfind(const T&) const;
    void binsert(const T&);
    void bremove(const T&);
    void inorder (std::ostream&) const;

private:
    bnode<T> *root;

};

///////////////////////////////////////////////////////////////////////
//This whole class should probably be a private nested class within the btree class
//as the btree is meant to be the outward facing class that is interacted with while
//bnode is the under the hood class that shouldn't be directly interacted with.
template <typename T>
class bnode {
public:
    bnode() : left(), right(0) {};
    bnode(const T& x) : left(0), right(0), data(x) {};
    ~bnode();
    bnode(const bnode<T>&);  


bool bfind(const T&) const;
void binsert(const T&);
bnode<T>* bremove(const T&);
T    predecessor() const;
void inorder(std::ostream) const;

private:
    bnode<T> *left, *right;
    T        data;

};



template <typename T>
bool btree<T>::bfind(const T& key) const {
    if (!root) return false;
    return root->bfind(key) return true;
}

template <typename T>
bool bnode<T>::bfind(const T& key) const {
    if (data == key) return true;
    if (key < data) {
        if (left) return left->bfind(key);
        else      return false;
    } else {
        if (right) return right->bfind(key);
        else       return false;
    }
}

template <typename T>
void btree<T>::binsert(const T& key) {
    if (root == 0) 
        root = new bnode<T>(key);
    else
        root->binsert(key);

} 

template <typename T>
void bnode<T>::binsert(const T& key) {
    if (key < data) {
        if (left) left->binsert(key);
        else left = new bnode<T>(key);
    } else {
        if (right) right->binsert(key);
        else right = new bnode<T>(key);
    }
    
} 

template <typename T>
btree<T>::~btree() {
    if (root) delete root;
    //Rest of btree is deallocated by compiler
}

template <typename T>
bnode<T>::~bnode() {
    if (left) delete left;
    if (right) delete right;
    //Rest of bnode is deallocated by compiler
}

template <typename T>
btree<T>::btree(const btree<T>& actual) {
    if(actual.root) root = bnode<T>(*(actual.root));
    else            root = 0;
}

template <typename T>
bnode<T>::bnode(const bnode<T>& actual) : bnode() {
    data = actual.data;
    if(actual.left) left = bnode<T>(*(actual.left));
    if(actual.right) right = bnode<T>(*(actual.right));
    
}

// x.left->predecessor()
// REQUIRES: Given x.left
// ENSURES:  RETVAL == predecessor of x.data
template <typename T>
T bnode<T>::predecessor() const {
    if(right) return right->predecessor();
    return data;
}

// REQUIRES: Given key
// Ensures:  Still a btree
template <typename T>
void btree<T>::bremove(const T& key) {
    //simply points to the top level bnode
    if (bfind(key)) root = root->bremove(key);
}

// REQUIRES: key in tree
template <typename T>
bnode<T>* bnode<T>::bremove(const T& key) {
    if(key == data) {
        if(!left && !right) { //No children
            delete this;
            return 0;
        }
        if(!left && right) { //Right child only
            bnode<T> *temp = right;
            right = 0;
            delete this;
        }
        if(left && !right) { //Left child only
            bnode<T> *temp = left;
            left = 0;
            delete this;
            return temp;
        }
        //Two children
        data = left->predecessor();
        left = left->bremove(data);

    } else {
        if (key < data)
            left = left->bremove(key);
        else 
            right = right->bremove(key);
    }
    return this;
}

