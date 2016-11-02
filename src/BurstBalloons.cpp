#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int maxSubCoins(int *list, int b, int e){
//		int max = 0,left,right;
//
//		if (b + 1 == e)
//			return 0;
//		if (b + 2 == e)
//			return list[b] * list[b + 1] * list[e];
//
//		for (int i = b + 1; i < e; i++){
//			left = maxSubCoins(list, b, i);
//			right = maxSubCoins(list, i, e);
//			if (left + right + list[b] * list[i] * list[e] > max)
//				max = left + right + list[b] * list[i] * list[e];
//		}
//		return max;
//	}
//
//	int maxCoins(vector<int>& nums) {
//		int n = nums.size(), i;
//		int *list = new int[n+2];
//
//		list[0] = 1;
//		list[n + 1] = 1;
//		for (i = 0; i < n; i++)
//			list[i + 1] = nums[i];
//
//		return maxSubCoins(list, 0, n + 1);
//	}
//};

//Given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on 
//it represented by array nums.You are asked to burst all the balloons.
//If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
//Here left and right are adjacent indices of i.After the burst, the left and right then becomes adjacent.

class Solution {
public:

	int maxCoins(vector<int>& nums) {
		int n = nums.size(), i, j, k, l;
		int *list = new int[n + 2];
		int temp_max, res;

		list[0] = 1;
		list[n + 1] = 1;
		for (i = 0; i < n; i++)
			list[i + 1] = nums[i];

		int **temp = new int*[n+2];
		for (i = 0; i < n + 2; i++)
			temp[i] = new int[n + 2];

		for (i = 0; i < n + 2; i++)
			for (j = 0; j < n + 2; j++)
				temp[i][j] = 0;

		for (i = 2; i < n + 2; i++){
			k = 0;
			j = i;
			while (j < n + 2){
				temp_max = 0;
				for (l = k + 1; l < j; l++)
					if (temp[k][l] + temp[l][j] + list[k] * list[l] * list[j] > temp_max)
						temp_max = temp[k][l] + temp[l][j] + list[k] * list[l] * list[j];
				temp[k][j] = temp_max;
				k++;
				j++;
			}
		}
		
		res = temp[0][n + 1];
		for (i = 0; i < n + 2; i++)
			delete[]temp[i];
		delete[]temp;

		return res;
	}
};

int BurstBalloons(){
	Solution a;
	vector<int> b = { 3, 1, 5, 8 };
	int i;

	cout << a.maxCoins(b) << endl;
	
	cin >> i;

	return 0;
}
