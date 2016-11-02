//
// Created by tlm on 2016/10/16.
//

#ifndef LECTCODE_PRACTICE_REDANDBLACK_H
#define LECTCODE_PRACTICE_REDANDBLACK_H

#include <iostream>

enum Color{red, black, nil};
struct treeNode{
    int key;
    struct treeNode *p;
    struct treeNode *left;
    struct treeNode *right;
    Color color;

    treeNode(){};
    treeNode(int _key):key(_key){
        p=left=right = NULL;
    };

    treeNode(int _key,struct treeNode *_p,struct treeNode *_left,struct treeNode *_right,
             Color _color):key(_key), p(_p), left(_left), right(_right), color(_color){};

    treeNode(int _key, Color _color):key(_key), color(_color){
        p = this;
        right = this;
        left = this;
    };
};

class redAndBlack{
public:
    treeNode *treeNil;

    redAndBlack(){
        treeNil = new treeNode(0, nil);
    }
    ~redAndBlack(){
        delete treeNil;
    }

    treeNode* RBinsert(treeNode *rootParent, treeNode *x);
    void RBdelete(treeNode *root, treeNode *z);
    void BSFsearch(treeNode *root);

private:
    void leftRotate(treeNode *root, treeNode *x);
    void rightRotate(treeNode *root, treeNode *x);
    void RBinsertFixup(treeNode *root, treeNode *x);
    void RBtranslate(treeNode *root, treeNode *u, treeNode *v);
    void RBdeleteFixup(treeNode *root, treeNode *x);
};

#endif //LECTCODE_PRACTICE_REDANDBLACK_H
