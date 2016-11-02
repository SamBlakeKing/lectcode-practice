//
// Created by tlm on 2016/10/18.
//
#include "../include/SerializeandDeserializeBinaryTree.h"

template<typename T>
string m_to_string(const T& n){
    ostringstream stm;
    stm<<n;
    return stm.str();
}

// Encodes a tree to a single string.
string SerializeandDeserializeBinaryTree::serialize(TreeNode* root) {
    if(root == NULL)
        return "[null]";

    queue<TreeNode*> que;
    que.push(root);
    vector<char> s;
    TreeNode *p;

    s.push_back('[');
    while(!que.empty()){
        p=que.front();
        que.pop();
        if(p==NULL){
            s.push_back('n');
            s.push_back('u');
            s.push_back('l');
            s.push_back('l');
            s.push_back(',');
        }else{
            string t = m_to_string(p->val);
            for(int i=0; i<t.size(); i++)
                s.push_back(t[i]);
            s.push_back(',');
            que.push(p->left);
            que.push(p->right);
        }
    }
    s[s.size()-1] = ']';
    return string(s.begin(), s.end());
}

// Decodes your encoded data to tree.
TreeNode* SerializeandDeserializeBinaryTree::deserialize(string data) {
    const char *c_data = data.c_str();
    char c_num[100];
    int index = 1;
    int len = 0;

    TreeNode *root = NULL;
    TreeNode **p;
    queue<TreeNode **> que;
    que.push(&root);
    while(!que.empty()){
        p = que.front();
        que.pop();
        len = 0;
        while(c_data[index+len] != ',' && c_data[index+len] != ']')len++;
        memcpy(c_num,c_data+index, len* sizeof(char));
        c_num[len] = '\0';

        if(strcmp(c_num, "null") == 0)
            *p = NULL;
        else{
            *p = new TreeNode(atoi(c_num));
            que.push(&((*p)->left));
            que.push(&((*p)->right));
        }
        index = index + len + 1;
    }
    return root;
}

