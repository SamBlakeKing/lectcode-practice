#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int myTarget;
	vector<int> myCandidates;
	vector<vector<int> > result;
	vector<int> temp;

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		myTarget = target;
		sort(candidates.begin(), candidates.end());
		myCandidates = candidates;
		/*for (int i = 0; i < myCandidates.size(); i++)
			cout << myCandidates[i] << " ";
		cout << endl;*/

		fun(0, 0);
		return result;
	}

	void fun(int sum, int index){
		int i;

		if (sum == myTarget)
			result.push_back(vector<int>(temp));
		if (index == myCandidates.size() || sum + myCandidates[index] > myTarget)
			return;

		for (i = index; i < myCandidates.size(); i++){
			while (sum + 2 * myCandidates[i] <= myTarget){
				sum += myCandidates[i];
				temp.push_back(myCandidates[i]);
			}
			
			if (sum + myCandidates[i] == myTarget){
				temp.push_back(myCandidates[i]);
				result.push_back(vector<int>(temp));
				temp.pop_back();
			}

			while (!temp.empty() && myCandidates[i] == temp.back()){
				fun(sum, i + 1);
				temp.pop_back();
				sum -= myCandidates[i];
			}
		}

	}
};

int CombinationSum(){
	Solution a;
	vector<int> b = { 8, 7, 4, 3 };
	vector<int> temp;
	vector<vector<int> > result;
	int i,j;

	result = a.combinationSum(b, 11);
	for (i = 0; i < result.size(); i++){
		for (j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}

	cin >> i;
	return 1;
}