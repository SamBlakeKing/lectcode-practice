#include <iostream>
#include <vector>
using namespace std;

class Solution {
	struct myTree{
		int begin;
		int end;
		int max;
		struct myTree *parent;
		struct myTree *left;
		struct myTree *right;
		myTree(){};
	};

	void checkMax(struct myTree*c, int &max){
		struct myTree *p = c->parent;
		struct myTree *temp;
		while (p){
			if (p->begin < -100)
				c = c;

			//cout << p->begin << ":" << p->end << endl;

			if (p->begin == c->end + 1){
				p->begin = c->begin;
				p->max += c->max;
				if (c == c->parent->left){
					c->parent->left = c->left;
					if (c->left)
						c->left->parent = c->parent;
				}
				else{
					c->parent->right = c->left;
					if (c->left)
						c->left->parent = c->parent;
				}
				delete c;
				c = p;
				p = p->parent;
				if (c->end - c->begin + 1 > max){
					max = c->end - c->begin + 1;
					//cout << c->begin << ":" << c->end << endl;
				}
			}
			else if ( p->end == c->begin - 1){
				p->end = c->end;
				p->max += c->max;
				if (c == c->parent->left){
					c->parent->left = c->right;
					if (c->right)
						c->right->parent = c->parent;
				}
				else{
					c->parent->right = c->right;
					if (c->right)
						c->right->parent = c->parent;
				}
				delete c;
				c = p;
				p = p->parent;
				if (c->end - c->begin + 1 > max){
					max = c->end - c->begin + 1;
					//cout << c->begin << ":" << c->end << endl;
				}
			}
			else {
				p = p->parent;
			}

			//cout << c->begin << ":" << c->end << ":" << c->max << endl;
		}
	}

	void insertTree(struct myTree *root, int &max, int num){
		struct myTree *c = root;
		struct myTree *p = NULL;
		while (c){
			if (c->begin > num){
				p = c;
				c = c->left;
			}
			else if(c->end < num){
				p = c;
				c = c->right;
			}
			else{
				/*c->max++;
				if (c->max >max)
					max = c->max;*/
				return;
			}
		}

		struct myTree *temp = new struct myTree();
		temp->begin = temp->end = num;
		temp->left = temp->right = NULL;
		temp->parent = p;
		temp->max = 1;
		if (p->begin > num){
			p->left = temp;
		}
		else if (p->end < num){
			p->right = temp;
		}
		else
			delete temp;

		checkMax(temp, max);
	}

public:
	int longestConsecutive(vector<int>& nums) {
		int max = 1;
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return 1;
		struct myTree *root = new struct myTree();
		root->parent = root->left = root->right = NULL;
		root->begin = root->end = nums[0];
		root->max = 1;

		for (int i = 1; i < nums.size(); i++)
			insertTree(root, max, nums[i]);
		
		//cout << root->left->begin << ":" << root->left->end << endl;
		return max;
	}
};

int LongestConsecutiveSequence(){
	Solution a;
	vector<int> nums = { 1, -8, 7, -2, -4, -4, 6, 3, -4, 0, -7, -1, 5, 1, -9, -3 };
	int res = a.longestConsecutive(nums);
	
	cout << res << endl;
	cin >> res;

	return 0;
}


