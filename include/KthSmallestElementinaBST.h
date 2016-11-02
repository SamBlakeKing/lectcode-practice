//
// Created by tlm on 2016/10/17.
//

#ifndef LECTCODE_PRACTICE_KTHSMALLESTELEMENTINABST_H
#define LECTCODE_PRACTICE_KTHSMALLESTELEMENTINABST_H

#include <iostream>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class KthSmallestElementinaBST {
public:
    int Solution(TreeNode* root, int k);
};

#endif //LECTCODE_PRACTICE_KTHSMALLESTELEMENTINABST_H
