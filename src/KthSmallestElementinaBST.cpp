//
// Created by tlm on 2016/10/17.
//
#include "../include/KthSmallestElementinaBST.h"

int KthSmallestElementinaBST::Solution(TreeNode* root, int k) {
    stack<TreeNode*> q;
    TreeNode *p = root;
    while(p || !q.empty()){
        while(p){
            q.push(p);
            p = p->left;
        }
        p = q.top();
        if(--k == 0)
            return p->val;
        q.pop();
        p = p->right;
    }
}