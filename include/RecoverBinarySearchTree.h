//
// Created by tlm on 2016/10/18.
//

#ifndef LECTCODE_PRACTICE_RECOVERBINARYSEARCHTREE_H
#define LECTCODE_PRACTICE_RECOVERBINARYSEARCHTREE_H

#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode* root);
};

#endif //LECTCODE_PRACTICE_RECOVERBINARYSEARCHTREE_H
