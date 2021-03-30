// Decided to move implementation to .h files because


// #include "AvlNode.h"

// template<class T>
// AvlNode<T>::AvlNode(const T& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h) :
//     data{d}, left{leftChild}, right{rightChild}, height{h} {}

// template<class T>
// AvlNode<T>::AvlNode(const T&& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h) :
//     data{std::move(d)}, left{leftChild}, right{rightChild}, height{h} {}
