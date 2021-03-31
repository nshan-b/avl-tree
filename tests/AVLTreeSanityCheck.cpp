#include <gtest/gtest.h>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "AvlTree.h"

#define NUM_INSERTS 10000
#define DISTRIBUTION_MIN -5000
#define DISTRIBUTION_MAX 5000
#define NUM_DELETIONS 3725


TEST(AVLSanityCheck, HandlesInsertion) {
    AvlTree<int>* tree = new AvlTree<int>();

    // Create a distribution of numbers
    auto rd = std::random_device {}; 
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<int> intDist(DISTRIBUTION_MIN, DISTRIBUTION_MAX);

    std::vector<int> inserts;
    inserts.reserve(NUM_INSERTS);

    for (int i = 0; i < NUM_INSERTS; i++) {
        inserts.push_back(intDist(generator));
    }

    tree->add(inserts);

    // Re-sort inserts & delete duplicates to check for size equivalency
    std::sort(inserts.begin(), inserts.end());
    inserts.erase(std::unique(inserts.begin(), inserts.end()), inserts.end());
    
    std::ostringstream sortedStr;
    for (auto it = inserts.begin(); it != inserts.end(); it++) {
        sortedStr << *it << " ";
    }

    // Expect both the size of the tree and the insertions to be the same
    EXPECT_EQ(tree->getSize(), (long)inserts.size());

    // Expect a string of the sorted vector of inputs (w/o duplicates)
    // to equal the string of the in-order traversal of our AVL tree 
    EXPECT_EQ(tree->printStr(false), sortedStr.str());
}

TEST(AVLSanityCheck, HandlesDeletion) {
    AvlTree<int>* tree = new AvlTree<int>();

    auto rd = std::random_device {}; 
    std::default_random_engine generator { rd() };
    std::uniform_int_distribution<int> intDist(DISTRIBUTION_MIN, DISTRIBUTION_MAX);

    std::vector<int> inserts;
    inserts.reserve(NUM_INSERTS);

    for (int i = 0; i < NUM_INSERTS; i++) {
        inserts.push_back(intDist(generator));
    }

    tree->add(inserts);

    // Re-sort vector - we are erasing duplicates still
    std::sort(inserts.begin(), inserts.end());
    inserts.erase(std::unique(inserts.begin(), inserts.end()), inserts.end());

    // Shuffle vector
    auto formerLen = inserts.size();
    std::shuffle(std::begin(inserts), std::end(inserts), generator);

    // Grab subsets of the shuffled vector
    std::vector<int> deletionSubset(inserts.begin(), inserts.begin() + NUM_DELETIONS);
    std::vector<int> remainingSubset(inserts.begin() + NUM_DELETIONS, inserts.end());

    auto delSubsetLen = deletionSubset.size();

    // Erase based on shuffle
    for (auto it = deletionSubset.begin(); it != deletionSubset.end(); it++) {
        tree->erase(*it);
    }


    // Sort the remaining subset for comparing both strings (no duplicates currently present)
    std::sort(remainingSubset.begin(), remainingSubset.end());
    std::ostringstream sortedStr;
    for (auto it = remainingSubset.begin(); it != remainingSubset.end(); it++) {
        sortedStr << *it << " ";
    }

    // std::cout << tree->getSize() << std::endl;
    // std::cout << "formerLen: " << formerLen << std::endl;
    // std::cout << "delSubsetLen: " << delSubsetLen << std::endl;
    // std::cout << "NUM_DEL: " << NUM_DELETIONS << std::endl;

    EXPECT_EQ(tree->getSize(), (formerLen - delSubsetLen));
    EXPECT_EQ(tree->getSize(), (formerLen - NUM_DELETIONS));
    EXPECT_EQ(tree->printStr(false), sortedStr.str());
}