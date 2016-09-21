#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//such as nums = [1,2,2]==>
							//[
							//	[2],
							//	[1],
							//	[1, 2, 2],
							//	[2, 2],
							//	[1, 2],
							//	[]
							//]
//better solution from online;

//class Solution {
//public:
//	vector<vector<int> > subsetsWithDup(vector<int> &S) {
//		vector<vector<int> > totalset = { {} };
//		sort(S.begin(), S.end());
//		for (int i = 0; i<S.size();){
//			int count = 0; // num of elements are the same
//			while (count + i<S.size() && S[count + i] == S[i])  count++;
//			int previousN = totalset.size();
//			for (int k = 0; k<previousN; k++){
//				vector<int> instance = totalset[k];
//				for (int j = 0; j<count; j++){
//					instance.push_back(S[i]);
//					totalset.push_back(instance);
//				}
//			}
//			i += count;
//		}
//		return totalset;
//	}
//};

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<int> temp;
		vector<vector<int>> result;
		fun(result, nums, temp, 0);

		return result;
	}
	void fun(vector<vector<int>>& result,vector<int>& nums, vector<int>&temp, int index){
		if (index == nums.size()){
			result.push_back(vector<int>(temp));
			return;
		}

		int value = nums[index++];
		temp.push_back(value);
		while (index < nums.size() && value == nums[index]){
			index++;
			temp.push_back(value);
		}
		while (!temp.empty() && value == temp.back()){
			fun(result, nums, temp, index);
			temp.pop_back();
		}
		fun(result, nums, temp, index);
	}
};

int main(){
	Solution a;
	vector<int> b = { 1, 2, 2 },temp;
	vector<vector<int> >c;
	int i, j;

	c = a.subsetsWithDup(b);
	for (i = 0; i < c.size(); i++){
		temp = c[i];
		for (j = 0; j < temp.size(); j++)
			cout << temp[j] << " ";
		cout << endl;
	}

	cin >> i;

	return 0;
}