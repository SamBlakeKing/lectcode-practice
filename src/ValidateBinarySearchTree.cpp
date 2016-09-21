#include <iostream>
using namespace std;

//other Solution
//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		TreeNode* prev = NULL;
//		return validate(root, prev);
//	}
//	bool validate(TreeNode* node, TreeNode* &prev) {
//		if (node == NULL) return true;
//		if (!validate(node->left, prev)) return false;
//		if (prev != NULL && prev->val >= node->val) return false;
//		prev = node;
//		return validate(node->right, prev);
//	}
//};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;

		int min, max;
		return searchBST(root, min, max);
	}

	bool searchBST(TreeNode* root, int &min, int &max){
		int temp = root->val;
		int left_min, left_max, right_min, right_max;

		//cout << temp << endl;
		if (root->left){
			if (searchBST(root->left, left_min, left_max)){
				if (left_max >= temp)
					return false;
				min = left_min;
			}
			else
				return false;
		}
		else
			min = temp;

		if (root->right){
			if (searchBST(root->right, right_min, right_max)){
				if (right_min <= temp)
					return false;
				max = right_max;
			}
			else
				return false;
		}
		else
			max = temp;

		//cout << min << " " << max << endl;
		return true;
	}
};

int main(){
	Solution a;
	int i;
	TreeNode *root = new TreeNode(5);
	TreeNode *left = new TreeNode(2);
	TreeNode *right = new TreeNode(7);

	root->left = left;
	root->right = right;

	left->left = new TreeNode(1);
	left->right = new TreeNode(3);

	if (a.isValidBST(root))
		cout << "The tree is BST." << endl;

	cin >> i;

	return 0;
}