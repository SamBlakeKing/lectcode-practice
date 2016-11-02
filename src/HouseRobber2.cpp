#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		time_t start, stop;
		start = clock();

		int max_stolen1, max_not_stolen1, max_stolen2, max_not_stolen2;
		int max = 0, i, temp;
		int n = nums.size();

		switch (n){
			case 0:return 0;
			case 1:return nums[0];
			case 2:return nums[0] > nums[1] ? nums[0] : nums[1];
			case 3:max = nums[0] > nums[1] ? nums[0] : nums[1];return max > nums[2] ? max : nums[2];
		}

		max_stolen1 = nums[0] + nums[2];
		max_not_stolen1 = nums[0];
		max_stolen2 = nums[2];
		max_not_stolen2 = nums[1];

		for (i = 3; i < n; i++){
			temp = max_not_stolen1;
			max_not_stolen1 = max_not_stolen1>max_stolen1 ? max_not_stolen1 : max_stolen1;
			max_stolen1 = temp + nums[i];
			
			temp = max_not_stolen2;
			max_not_stolen2 = max_not_stolen2>max_stolen2 ? max_not_stolen2 : max_stolen2;
			max_stolen2 = temp + nums[i];
		}

		max = max_not_stolen1;
		if (max_stolen2 > max)
			max = max_stolen2;
		if (max_not_stolen2 > max)
			max = max_not_stolen2;

		stop = clock();
		cout << "the running time:" << (double)(stop - start)<< endl;

		return max;
	}
};

int HouseRobber2(){
	Solution a;
	vector<int> b = { 2, 7, 7, 7, 4 };
	int i;

	cout << a.rob(b) << endl;

	cin >> i;
	return 0;
}