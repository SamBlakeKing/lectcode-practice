#include <iostream>

using namespace std;

enum Color{red, black, nil};
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
    x->left = y->right;
    y->right->p = x;
    y->right = x;
    x->p = y;
}

static treeNode *treeNil;
treeNil->p = treeNil;
treeNil->left = treeNil;
treeNil->right = treeNil;
treeNil->color = nil;

void RBinsertFixup(treeNode *root, treeNode *x){
	while(x->p->color == red){
		if(x->p == x->p->p->left){
			if(x->p->p->right->color == red){
				x->p->color = black;
				x->p->p->right->color = black;
				x->p->p->color = red;
				x = x->p->p;
			}else{
				if(x == x->p->right){
					leftRotate(root, x->p);
					x = x->left;	
				}
				rightRotate(root, x->p->p);
				x->p->color = black;
				x->p->right = red;
			}
		}else{
			if(x->p->p->left->color == red){
				x->p->color = black;
				x->p->p->left->color = black;
				x->p->p->color = red;
				x = x->p->p;
			}else{
				if(x == x->p->left){
					rightRotate(root, x->p);
					x = x->right;	
				}
				leftRotate(root, x->p->p);
				x->p->color = black;
				x->p->left = red;
			}
		}
	}
	root->color = black;
}

void RBinsert(treeNode *rootParent, treeNode *x){
	treeNode *y = rootParent->left;
	treeNode *p = rootParent;

	while(y != treeNil)
		if(y->key == x->key){
			delete x;
			return;
		}else if(y->key > x->key){
			y = y->left;
			p = y;
		}
		else{
			y = y->right;
			p = y;
		}

	x->left = x->right = treeNil;
	x->p = p;
	if(p == treeNil){
		p->left = p->right = x;
		x->p = p;
	}
	else if(x->key < p->key)
		p->left = x;
	else
		p->right = x;
	x->color = red;
}

void RBtranslate(treeNode *root, treeNode *u, treeNode *v){
	if(root->p == treeNil){
		treeNil->left = treeNil->right = v;
	}else if(u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void RBdeleteFixup(treeNode *root, treeNode *x){
	treeNode *w;
	while(x->p != treeNil && x->color == black)
		if(x == x->p->left){
			w = x->p->right;
			if(w->color ==red){
				leftRotate(root, x->p);
				w->color = black;
				x->p->color = red;
				w = x->p->right;
			}
			if(w->right->color==black && w->left->color==black){
				w->color = red;
				x = x->p;
			}else{
				if(w->right->color == black){
					rightRotate(root, w);
					w->color = red;
					x->p->right = black;
					w = x->p->right;
				}
				leftRotate(root, x->p);
				w->color = x->p->color;
				x->p->color = black;
				w->right = black;
				x = root;
			}
		}else{
			w = x->p->left;
			if(w->color ==red){
				rightRotate(root, x->p);
				w->color = black;
				x->p->color = red;
				w = x->p->right;
			}
			if(w->left->color==black && w->right->color==black){
				w->color = red;
				x = x->p;
			}else{
				if(w->left->color == black){
					leftRotate(root, w);
					w->color = red;
					x->p->left = black;
					w = x->p->left;
				}
				rightRotate(root, x->p);
				w->color = x->p->color;
				x->p->color = black;
				w->left = black;
				x = root;
			}
		}
	x->color = black;
}

void RBdelete(treeNode *root, treeNode *z){
	treeNode *y = z;
	treeNode *x;
	Color y_origin_color = z->color;
	if(z->left == treeNil){
		x = z->right;
		RBtranslate(root, z, z->right)
	}else if(z->right == treeNil){
		x = z->left;
		RBtranslate(root, z, z->left);
	}else{
		y = z->right;
		while(y->left != treeNil)y=y->left;
		y_origin_color = y->color;
		x = y->right;
		if(y->p == z)
			x->p = y;
		else{
			RBtranslate(root, y, x);
			y->right = z->right;
			y->right->p = y;
		}
		RBtranslate(root, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}
	if(y_origin_color == black)
		RBdeleteFixup(root, x);
}
