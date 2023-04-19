#include <string>
#include <iostream>

#include "BinStrTree.h"

using std::string;
using std::cout;
using std::endl;

// copy constructor
BinStrTree::BinStrTree(const BinStrTree &rhs) : root(rhs.root) {
    root->copyTree();
}

// destructor
BinStrTree::~BinStrTree() {
    if (root->delTree() != 0) {
        delete root;
    }
}

