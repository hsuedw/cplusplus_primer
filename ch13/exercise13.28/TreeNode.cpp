#include <string>
#include <iostream>

#include "TreeNode.h"

using std::string;
using std::cout;
using std::endl;

// copy constructor
TreeNode::TreeNode(const TreeNode &rhs) :
    value(rhs.value), count(1) {
    if (rhs.left != nullptr) {
        left->copyTree();
    } else {
        left = nullptr;
    }

    if (rhs.right != nullptr) {
        right->copyTree();
    } else {
        right = nullptr;
    }
}

// destructor
TreeNode::~TreeNode() {
    if (count != 0)  {
        delTree();
    }
}

void TreeNode::copyTree() {
    if (left != nullptr) {
        left->copyTree();
    }

    if (right != nullptr) {
        right->copyTree();
    }

    ++count;
}

int TreeNode::delTree() {
    if (left != nullptr && left->delTree() != 0) {
        delete left;
    }

    if (right != nullptr && right->delTree() != 0) {
        delete right;
    }
    --count;
    return count;
}
