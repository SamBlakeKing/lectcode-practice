#include "../include/redAndBlack.h"

void redAndBlack::leftRotate(treeNode *root, treeNode *x){
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

void redAndBlack::rightRotate(treeNode *root, treeNode *x){
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

void redAndBlack::RBinsertFixup(treeNode *root, treeNode *x){
	while(x->p->color == Color::red){
		if(x->p == x->p->p->left){
			if(x->p->p->right->color == Color::red){
				x->p->color = Color::black;
				x->p->p->right->color = Color::black;
				x->p->p->color = Color::red;
				x = x->p->p;
			}else{
				if(x == x->p->right){
					leftRotate(root, x->p);
					x = x->left;	
				}
				rightRotate(root, x->p->p);
				x->p->color = black;
				x->p->right->color = red;
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
				x->p->left->color = red;
			}
		}
	}
	root->color = black;
}

treeNode* redAndBlack::RBinsert(treeNode *rootParent, treeNode *x){
	treeNode *y = rootParent->left;
	treeNode *p = rootParent;

	while(y != treeNil)
		if(y->key == x->key){
			delete x;
			return y;
		}else if(y->key > x->key){
            p = y;
			y = y->left;
		}
		else{
            p = y;
			y = y->right;
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

    return NULL;
}

void redAndBlack::RBtranslate(treeNode *root, treeNode *u, treeNode *v){
	if(u->p == treeNil){
		treeNil->left = treeNil->right = v;
	}else if(u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void redAndBlack::RBdeleteFixup(treeNode *root, treeNode *x){
	treeNode *w;
	while(x->p != treeNil && x->color == black)
		if(x == x->p->left){
			w = x->p->right;
			if(w->color ==red){
                w->color = black;
                x->p->color = red;
				leftRotate(root, x->p);
				w = x->p->right;
			}
			if(w->right->color==black && w->left->color==black){
				w->color = red;
				x = x->p;
			}else{
				if(w->right->color == black){
                    w->left->color = Color::black;
                    w->color = red;
					rightRotate(root, w);
					w = x->p->right;
				}
                w->color = x->p->color;
                x->p->color = black;
                w->right->color = black;
				leftRotate(root, x->p);
				x = root;
			}
		}else{
            w = x->p->left;
            if(w->color ==red){
                w->color = black;
                x->p->color = red;
                leftRotate(root, x->p);
                w = x->p->left;
            }
            if(w->left->color==black && w->right->color==black){
                w->color = red;
                x = x->p;
            }else{
                if(w->left->color == black){
                    w->right->color = Color::black;
                    w->color = red;
                    rightRotate(root, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = black;
                w->left->color = black;
                leftRotate(root, x->p);
                x = root;
            }
		}
	x->color = black;
}

void redAndBlack::RBdelete(treeNode *root, treeNode *z){
	treeNode *y = z;
	treeNode *x;
	Color y_origin_color = z->color;
	if(z->left == treeNil){
		x = z->right;
		RBtranslate(root, z, z->right);
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

void redAndBlack::BSFsearch(treeNode *root){
    if(root == treeNil)
        return;
    BSFsearch(root->left);
    std::cout<<root->key<<" ";
    BSFsearch(root->right);
}