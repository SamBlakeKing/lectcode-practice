//
// Created by tlm on 2016/10/18.
//

#ifndef LECTCODE_PRACTICE_SERIALIZEANDDESERIALIZEBINARYTREE_H
#define LECTCODE_PRACTICE_SERIALIZEANDDESERIALIZEBINARYTREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SerializeandDeserializeBinaryTree {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};

#endif //LECTCODE_PRACTICE_SERIALIZEANDDESERIALIZEBINARYTREE_H
