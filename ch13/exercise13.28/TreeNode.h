#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class TreeNode {
public:
    // The default constructor
    TreeNode() : 
        value(""), count(1), left(nullptr), right(nullptr) {}

    // constructor
    TreeNode(const string &value, TreeNode *left = nullptr, TreeNode *right = nullptr) :
        value(value), count(1), left(left), right(right) {}

    // copy constructor
    TreeNode(const TreeNode &rhs);

    // copy-assignement operator
    TreeNode &operator=(const TreeNode &rhs) = delete;

    // destructor
    ~TreeNode();

    void copyTree();
    int delTree();
private:
    string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};

#endif //__TREE_NODE_H__
