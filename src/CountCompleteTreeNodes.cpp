#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int countNodes(TreeNode* root) {
		int left_min, left_max, right_min, right_max;
		int height;
		int i = 0;

		height = left_min = depthTree(root, true);
		right_max = depthTree(root, false);
		if (!left_min)
			return 0;
		if (right_max == left_min)
			return pow(2, left_min) - 1;

		//cout << left_min << " " << right_max << endl;

		int *result = new int[left_min - 1];
		memset(result, 0, (left_min - 1)*sizeof(int));

		while (root){
			if (!root->right)
				if (!root->left)
					break;
				else{
					result[i++] = 1;
					break;
				}

			left_min = depthTree(root->left, true);
			left_max = depthTree(root->left, false);
			right_min = depthTree(root->right, true);
			right_max = depthTree(root->right, false);

			if (right_max != right_min){
				result[i++] = 1;
				root = root->right;
			}
			else if (left_max != left_min){
				result[i++] = 0;
				root = root->left;
			}
			else if (left_min == right_min){
				break;
			}
			else{
				result[i++] = 1;
				break;
			}
		}

		int temp = 0;
		for (i = 0; i < height - 1; i++){
			//cout << result[i] << endl;
			temp = temp * 2 + result[i];
		}

		//cout << height << " " << temp << " " << pow(2,height-1) << endl;
		return pow(2, height - 1) + temp - 1;
	}

	int depthTree(TreeNode* root,bool left){
		int num = 0;

		if (root == NULL)
			return num;
		while (root){
			num++;
			if (left)
				root = root->left;
			else
				root = root->right;
		}

		return num;
	}
};

int CountCompleteTreeNodes(){
	Solution a;
	TreeNode *root = new TreeNode(0);
	int i;
	TreeNode *left = new TreeNode(0);
	TreeNode *right = new TreeNode(0);
	root->left = left;
	root->right = right;
	left->left = new TreeNode(0);
	left->right = new TreeNode(0);
	right->left = new TreeNode(0);
	right->right = new TreeNode(0);

	cout << a.countNodes(root) << endl;
	cin >> i;

	return 0;
}