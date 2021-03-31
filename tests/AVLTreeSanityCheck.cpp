#include <gtest/gtest.h>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include "AvlTree.h"

#define NUM_INSERTS 10000
#define DISTRIBUTION_MIN -5000
#define DISTRIBUTION_MAX 5000


TEST(AVLSanityCheck, HandlesInsertion) {

    AvlTree<int>* tree = new AvlTree<int>();

    // Create a distribution of numbers
    std::default_random_engine generator;
    std::uniform_int_distribution<int> intDist(DISTRIBUTION_MIN, DISTRIBUTION_MAX);

    std::vector<int> inserts;
    inserts.reserve(NUM_INSERTS);

    for (int i = 0; i < NUM_INSERTS; i++) {
        inserts.push_back(intDist(generator));
    }

    tree->add(inserts);


    // Re-sort inserts and delete duplicates to check for size equivalency
    std::sort(inserts.begin(), inserts.end());
    inserts.erase(std::unique(inserts.begin(), inserts.end()), inserts.end());
    
    
    std::ostringstream sortedStr;
    for (auto i = inserts.begin(); i != inserts.end(); i++) {
        sortedStr << *i << " ";
    }

    EXPECT_EQ(tree->getSize(), (long)inserts.size());
    EXPECT_EQ(tree->printStr(false), sortedStr.str());
}