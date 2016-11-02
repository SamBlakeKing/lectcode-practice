//
// Created by tlm on 2016/11/1.
//

#ifndef LECTCODE_PRACTICE_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#define LECTCODE_PRACTICE_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ConstructBinaryTreefromPreorderandInorderTraversal {
public:
    typedef vector<int>::iterator m_iterator;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

private:
    void __buildTree(m_iterator p_first,m_iterator p_last, m_iterator i_first,
                     m_iterator i_last, TreeNode** root);
};

#endif //LECTCODE_PRACTICE_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H
