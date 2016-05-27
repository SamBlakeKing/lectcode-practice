#include <iostream>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		queue<TreeLinkNode* >temp;
		TreeLinkNode *last;
		TreeLinkNode *cur;
		if (root == NULL)
			return;
		
		temp.push(root);
		last = root;
		while (!temp.empty()){
			cur = temp.front();
			temp.pop();
			if (cur->left != NULL)
				temp.push(cur->left);
			if (cur->right != NULL)
				temp.push(cur->right);
			if (cur == last){
				cur->next = NULL;
				if (!temp.empty())
					last = temp.back();
			}
			else{
				if (!temp.empty())
					cur->next = temp.front();
				else
					cur->next = NULL;
			}
		}
	}
};

