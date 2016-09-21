//
// Created by dell on 9/21/16.
//

#ifndef LECTCODE_PRACTICE_UNIQUEBINARYSEARCHTREESII_H
#define LECTCODE_PRACTICE_UNIQUEBINARYSEARCHTREESII_H

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class UniqueBinarySearchTreesII{
public:
    std::vector<TreeNode*> generateTrees(int n);
    void infixSearch(TreeNode *root);

    int count;
};

#endif //LECTCODE_PRACTICE_UNIQUEBINARYSEARCHTREESII_H
