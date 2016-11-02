#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		if (0 == nums.size())
//			return 0;
//		vector<int> sequence;
//		int max = nums[0];
//		int i = 1,j;
//		int temp = nums[0];
//		if (max <= 0){
//			while (i < nums.size() && nums[i] <= 0){
//				if (nums[i] > max){
//					max = nums[i];
//				}
//				i++;
//			}
//			if (i < nums.size())
//				temp = nums[i];
//			else
//				return max;
//			i++;
//		}
//		
//		while (i < nums.size()){
//			if (nums[i] * temp < 0){
//				sequence.push_back(temp);
//				temp = nums[i++];
//			}
//			else{
//				temp = nums[i++] + temp;
//			}
//		}
//		sequence.push_back(temp);
//
//		int *sequence_forward = new int[sequence.size()];
//		//int *sequence_back = new int[sequence.size()];
//		for (i = 1, temp = sequence[0], sequence_forward[0] = sequence[0]; i < sequence.size(); i++){
//			temp = temp + sequence[i];
//			sequence_forward[i] = temp;
//		}
//		/*for (i = sequence.size() - 2, temp = sequence[sequence.size() - 1], sequence_back[sequence.size() - 1] = sequence[sequence.size() - 1]; i >= 0; i--){
//			temp = temp + sequence[i];
//			sequence_forward[i] = temp;
//		}*/
//		for (i = 0; i < sequence.size(); i = i + 2)
//			if (sequence_forward[i] > max)
//				max = sequence_forward[i];
//
//		for (i = 2; i < sequence.size(); i = i + 2)
//			for (j = i; j < sequence.size(); j = j + 2)
//				if (max < sequence_forward[j] - sequence_forward[i - 1])
//					max = sequence_forward[j] - sequence_forward[i - 1];
//
//		delete[]sequence_forward;
//		return max;
//	}
//};

//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//For example, given the array [-2, 1,-3, 4, -1, 2, 1,-5, 4],the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			if (nums.size() == 0)
				return 0;

			int MaxSofar = nums[0], MaxExtendHere = nums[0];
			for (int i = 1; i < nums.size(); i++){
				MaxExtendHere = nums[i]>(nums[i] + MaxExtendHere) ? nums[i] : (nums[i] + MaxExtendHere);
				MaxSofar = MaxSofar > MaxExtendHere ? MaxSofar : MaxExtendHere;
			}
			return MaxSofar;
		}
};

int MaximumSubarray(){
	Solution a;
	vector<int> b = {-2, 1,-3, 4, -1, 2, 1,-5, 4 };
	int i;
	cout << a.maxSubArray(b) << endl;

	cin >> i;
	return 0;
}