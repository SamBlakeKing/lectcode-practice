#include <iostream>

using namespace std;

enum Color{red, black};
struct treeNode{
    int key;
    struct treeNode *p;
    struct treeNode *left;
    struct treeNode *right;
    Color color;
};

void leftRotate(treeNode *root, treeNode *x){
    treeNode *y = x->right;
    y->p = x->p;
    if(x->p->left == x)
        x->p->left = y;
    else
        x->p->right = y;
    x->right = y->left;
    y->left->p = x;
    y->left = x;
    x->p = y;
}

void rightRotate(treeNode *root, treeNode *x){
    treeNode *y = x->left;
    y->p = x->p;
    if(x->p->left == x)
        x->p->left = y;
    else
        x->p->right = y;
    x->right = y->left;
    y->left->p = x;
    y->left = x;
    x->p = y;
}
