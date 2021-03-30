#include <iostream>
#include <vector>
#include "AvlTree.h"

int main() {
    AvlTree<int>* newTree = new AvlTree<int>();
    std::vector<int> inserts = {10, 7, 11, 42, 8, 9, 24, 3, 72, 9, 100, 75, 89, 88};

    newTree->add(inserts);

    newTree->print();
    return 1;
}