#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n > 9 || n < 1)
			return "";

		int *sequence = new int[n];
		char *result = new char[n+1];
		bool *mask = new bool[n];
		int i;

		k--;
		for (i = 0; i < n; i++)
			mask[i] = true;
		for (i = 2; i <= n; i++){
			sequence[n - i] = k % i;
			k = k / i;
		}

		for (i = 0; i < n - 1; i++){
			sequence[i] = numOfExit(mask, sequence[i]);
		}
		for (i = 0; i < n; i++)
			if (mask[i])
				break;
		sequence[n - 1] = i + 1;

		for (i = 0; i < n; i++)
			result[i] = '0' + sequence[i];
		result[n] = '\0';
		string temp = string(result);

		delete[]sequence;
		delete[]mask;
		delete[]result;

		return temp;
	}

	int numOfExit(bool *mask, int index){
		int i, j = 0;
		for (i = 0; i <= index;){
			if (mask[j])
				i++;
			j++;
		}
		mask[j - 1] = false;
		return j;
	}
};

int PermutationSequece(){
	Solution a;
	int i;
	for (i = 1; i <= 6; i++)
		cout << "the num " << i << " to" << a.getPermutation(3, i) << endl;

	cin >> i;
	return 0;
}