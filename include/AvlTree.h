#ifndef AVL_TREE_T
#define AVL_TREE_T

#include "../include/AvlNode.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

template <class T>
class AvlTree {
    private:
        AvlNode<T>* root;
        void insert(const T& d, AvlNode<T>*& n);
        void rotateRight(AvlNode<T>*& y);
        void rotateLeft(AvlNode<T>*& x);
        void balance(AvlNode<T>*& n);
        int height(AvlNode<T>* n);
    public:
        void add(T data);
        void add(std::vector<T> data);
        void print();
};

template<class T>
int AvlTree<T>::height(AvlNode<T>* n) {
    if (n == nullptr) {
        return -1;
    }
    else {
        return n->height;
    }
}

template<class T>
void AvlTree<T>::insert(const T& d, AvlNode<T>*& n) {
    if (n == nullptr) {
        n = new AvlNode<T>(d, nullptr, nullptr);
    }
    else if (d < n->data) {
        insert(d, n->left);
    }
    else if (d > n->data) {
        insert(d, n->right);
    }

    balance(n);
}

template<class T>
void AvlTree<T>::balance(AvlNode<T>*& n) {
    if (n == nullptr) {
        return;
    }

    // Check if left is imbalanced
    if (height(n->left) - height(n->right) > 1) {

        // Left-Left Case
        if (height(n->left->left) >= height(n->left->right)) {
            rotateRight(n);
        }

        // Left-Right Case
        else {
            rotateLeft(n->left);
            rotateRight(n);
        }
    }
    // Check if right is imbalanced
    else if (height(n->right) - height(n->left) > 1) {

        // Right-Right Case
        if (height(n->right->right) >= height(n->right->left)) {
            rotateLeft(n);
        }

        // Right-Left Case
        else {
            rotateRight(n->right);
            rotateLeft(n);
        }
    }

    // Update the height of the node
    n->height = std::max(height(n->left), height(n->right)) + 1;
}

/*
            {y}                                {x}
            / \                               /   \
        {x}     {C}     == RR(y) ==>        {A}    {y}
        / \                                        / \
      {A} {B}                                    {B} {C}
*/
template<class T>
void AvlTree<T>::rotateRight(AvlNode<T>*& y) {
    AvlNode<T>* x = y->left;
    y->left = x->right;
    x->right = y;

    // Update Heights
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), y->height) + 1;

    y = x;
}

/*
            {y}                                {x}
            / \                               /   \
        {x}     {C}     <== LR(x) ==        {A}    {y}
        / \                                        / \
      {A} {B}                                    {B} {C}
*/
template <class T>
void AvlTree<T>::rotateLeft(AvlNode<T>*& x) {
    AvlNode<T>* y = x->right;
    x->right = y->left;
    y->left = x;

    // Update Heights
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(x->height, height(y->right)) + 1;

    x = y;
}


//-----------------------------------------//
//---------- Auxillary functions ----------//
//-----------------------------------------//
template <class T>
void AvlTree<T>::add(T data) {
    insert(data, root);
}

template <class T>
void AvlTree<T>::add(std::vector<T> data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        insert(*it, root);
    }
}

template <class T>
void AvlTree<T>::print() {
    std::stack<AvlNode<T>*> stack;
    AvlNode<T>* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        
        std::cout << current->data << " ";

        current = current->right;
    }
}

#endif