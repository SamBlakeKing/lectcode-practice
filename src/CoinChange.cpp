#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		sort(coins.begin(), coins.end());
//		vector<int> result;
//
//		if (!amount)
//			return 0;
//		if (!coins.size())
//			return -1;
//		int temp = fun(coins, result, amount, coins.size() - 1);
//
//		/*for (int i = 0; i < result.size(); i++)
//			cout << result[i] << endl;*/
//
//		return temp;
//	}
//	int fun(vector<int>& coins, vector<int> &result, int leave, int index){
//		int n = leave / coins[index];
//		int i;
//		int temp;
//
//		if (index == 0)
//			if (leave % coins[index])
//				return -1;
//			else{
//				return result.size() + leave / coins[index];
//			}
//
//		int min = INT_MAX;
//		for (i = 0; i < n; i++)
//			result.push_back(coins[index]);
//		for (i = n; i > 0; i--){
//			temp = fun(coins, result, leave - i*coins[index], index - 1);
//			if (temp >= 0 && temp < min)
//				min = temp;
//
//			result.pop_back();
//		}
//
//		temp = fun(coins, result, leave - i*coins[index], index - 1);
//		if (temp >= 0 && temp < min)
//			min = temp;
//
//		return min==INT_MAX?-1:min;
//	}
//};
//
//int main(){
//	Solution a;
//	vector<int> b = { 186,419,83,408 };
//	int i;
//	cout << a.coinChange(b, 6249) << endl;
//	cin >> i;
//
//	return 0;
//}


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());

		if (!amount)
			return 0;
		if (!coins.size())
			return -1;
		int temp = INT_MAX;
		fun(coins, temp, 0, amount, coins.size() - 1);

		if (temp == INT_MAX)
			temp = -1;
		return temp;
	}
	int fun(vector<int>& coins, int &min,int current, int leave, int index){
		int n = leave / coins[index];
		int i;
		int temp;

		if (index == 0)
			if (leave % coins[index])
				return -1;
			else{
				if (min > current + n)
					min = current + n;
				return leave / coins[index];
			}
		
		if (min <= current + n)
			return -1;

		//n = (min - current) > n ? n : (min - current);
		int temp_min = INT_MAX;
		for (i = n; i >= 0; i--){
			temp = fun(coins, min, current + i, leave - i*coins[index], index - 1);

			if (temp + i < temp_min)
				temp_min = temp + i;
			/*if (temp != -1 && temp + current + i < min)
				min = temp + current + i;*/
		}

		return temp_min;
	}
};

int CoinChange(){
	Solution a;
	vector<int> b = { 438, 86, 218,138,358,152,129};
	int i;
	cout << a.coinChange(b, 7656) << endl;
	cin >> i;

	return 0;
}