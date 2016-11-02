//
// Created by tlm on 2016/11/1.
//
#include "../include/ConstructBinaryTreefromPreorderandInorderTraversal.h"

TreeNode* ConstructBinaryTreefromPreorderandInorderTraversal::buildTree(vector<int>& preorder,
                                                                        vector<int>& inorder) {
    TreeNode* root;
    __buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), &root);
    return root;
}

void ConstructBinaryTreefromPreorderandInorderTraversal::__buildTree(m_iterator p_first,
                                                                     m_iterator p_last,
                                                                     m_iterator i_first,
                                                                     m_iterator i_last,
                                                                      TreeNode** root){
    if(p_first == p_last || i_last == i_first){
        *root = NULL;
        return;
    }
    TreeNode *temp = new TreeNode(*p_first);
    m_iterator median = find(i_first, i_last, *p_first);
    size_t n = median - i_first;

    __buildTree(p_first+1, p_first+1+n, i_first, median, &(temp->left));
    __buildTree(p_first+1+n, p_last, median+1, i_last, &(temp->right));
    *root = temp;
}