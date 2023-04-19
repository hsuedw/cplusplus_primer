#ifndef __BIN_STR_TREE_H__
#define __BIN_STR_TREE_H__

#include <string>
#include <iostream>

#include "TreeNode.h"

using std::string;
using std::cout;
using std::endl;

class BinStrTree {
    // the default constructor
    BinStrTree() : root(nullptr) {}

    // constructor
    BinStrTree(TreeNode *root) : root(root) {}

    // copy constructor
    BinStrTree(const BinStrTree &rhs);

    // copy-assignment operator
    BinStrTree &operator=(const BinStrTree &rhs) = delete;

    // destructor
    ~BinStrTree();
private:
    TreeNode *root;
};

#endif //__BIN_STR_TREE_H__
