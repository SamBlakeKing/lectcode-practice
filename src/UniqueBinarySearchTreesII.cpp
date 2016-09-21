//
// Created by dell on 9/21/16.
//

#include "../include/UniqueBinarySearchTreesII.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef std::vector<TreeNode*> treeVector;

TreeNode* copyTree(TreeNode *root){
    if(root == NULL) return NULL;

    TreeNode *res = new TreeNode(root->val);
    res->left = copyTree(root->left);
    res->right = copyTree(root->right);
    return res;
}

void UniqueBinarySearchTreesII::infixSearch(TreeNode *root){
    if(root == NULL) return;
    infixSearch(root->left);
    root->val = count++;
    infixSearch(root->right);
}

std::vector<TreeNode*> UniqueBinarySearchTreesII::generateTrees(int n) {
    if(n==0){
        std::vector<TreeNode*> temp;
        return temp;
    }

    treeVector *treeVectorNums = new treeVector[n+1];
    TreeNode *root = new TreeNode(1);
    treeVectorNums[0].push_back(NULL);
    treeVectorNums[1].push_back(root);

    for(int i= 2; i<n+1;i++){
        for(int j=0;j<i;j++){
            for(int k = 0; k<treeVectorNums[j].size();k++)
                for (int l = 0; l < treeVectorNums[i-1-j].size(); ++l) {
                    root = new TreeNode(1);
                    root->left = copyTree(treeVectorNums[j][k]);
                    root->right = copyTree(treeVectorNums[i-1-j][l]);
                    treeVectorNums[i].push_back(root);
                }
        }
    }
    for(int i=0; i<treeVectorNums[n].size(); i++){
        count = 1;
        infixSearch(treeVectorNums[n][i]);
    }

    return treeVectorNums[n];
}
