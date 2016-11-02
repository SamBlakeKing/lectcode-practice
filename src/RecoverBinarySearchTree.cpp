//
// Created by tlm on 2016/10/18.
//

#include "../include/RecoverBinarySearchTree.h"

void RecoverBinarySearchTree::recoverTree(TreeNode* root) {
    TreeNode *firstElement = NULL;
    TreeNode *secondElement = NULL;
    TreeNode *preElement = new TreeNode(INT_MIN);

    stack<TreeNode*> sta;
    TreeNode *p = root;
    while(p){
        sta.push(p);
        p = p->left;
    }

    while(!sta.empty()){
        p = sta.top();
        sta.pop();
        if(firstElement == NULL && p->val <= preElement->val)
            firstElement = preElement;
        if(firstElement != NULL && p->val <= preElement->val)
            secondElement = p;

        preElement = p;
        if(p->right){
            p = p->right;
            while(p){
                sta.push(p);
                p = p->left;
            }
        }
    }

    int temp = secondElement->val;
    secondElement->val = firstElement->val;
    firstElement->val = temp;
}

