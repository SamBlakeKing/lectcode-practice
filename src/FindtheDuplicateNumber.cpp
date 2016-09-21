#include <iostream>
#include <vector>
 
using namespace std;


//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
//prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
//find the duplicate one.

//int findDuplicate3(vector<int>& nums)
//{
//	if (nums.size() > 1)
//	{
//		int slow = nums[0];
//		int fast = nums[nums[0]];
//		while (slow != fast)
//		{
//			slow = nums[slow];
//			fast = nums[nums[fast]];
//		}
//
//		fast = 0;
//		while (fast != slow)
//		{
//			fast = nums[fast];
//			slow = nums[slow];
//		}
//		return slow;
//	}
//	return -1;
//}

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int b = 1, e = nums.size();
		int less, more, temp, median;

		if (0 == e)
			return 0;
		e = e - 1;
		while (b <= e){
			temp = 0;
			less = 0;
			more = 0;
			median = (b + e) / 2;
			
			for (auto i = nums.cbegin(); i != nums.cend(); i++)
				if (*i>= b && *i<=e)
					if (*i == median)
						temp++;
					else if (*i > median)
						more++;
					else
						less++;

			//cout << median << " " << temp << " " << less << " " << more << endl;
			if (temp >= 2)
				return median;
			else if (median - b < less)
				e = median - 1;
			else if (e - median < more)
				b = median + 1;
		}

		return 0;
	}
};

int main(){
	Solution a;
	vector<int> b = { 1, 1, 2, 3, 4 };
	int i;

	cout << a.findDuplicate(b) << endl;

	cin >> i;

	return 0;
}