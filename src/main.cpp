#include <iostream>
#include <vector>
#include "AvlTree.h"

int main() {
    AvlTree<int>* newTree = new AvlTree<int>();

    // Inserting duplicates doesn't count
    std::vector<int> inserts = {10, 7, 11, 42, 8, 9, 24, 3, 72, 9, 100, 75, 89, 88};
    std::vector<int> deserts = {7, 11, 89, 42};

    newTree->add(inserts);
    newTree->erase(deserts);
    newTree->print();

    return 1;
}