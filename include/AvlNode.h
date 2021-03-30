#ifndef AVL_NODE_T
#define AVL_NODE_T

// enum BalanceFactor {left_higher, equal_height, right_higher};

template <class T>
class AvlNode {
    public:
        T data;
        AvlNode<T>* left;
        AvlNode<T>* right;
        int height;
        AvlNode<T>(const T& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h = 0);
        AvlNode<T>(const T&& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h = 0);
};

template<class T>
AvlNode<T>::AvlNode(const T& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h) :
    data{d}, left{leftChild}, right{rightChild}, height{h} {}

template<class T>
AvlNode<T>::AvlNode(const T&& d, AvlNode<T>* leftChild, AvlNode<T>* rightChild, int h) :
    data{std::move(d)}, left{leftChild}, right{rightChild}, height{h} {}

#endif