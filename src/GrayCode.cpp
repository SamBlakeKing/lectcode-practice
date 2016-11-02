#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res = {0};
		int i,j;

		if (0 == n)
			return res;

		res.push_back(1);
		for (i = 1; i < n; i++){
			for (j = res.size() - 1; j >= 0; j--)
				res.push_back((res[j] | (1 << i)));
		}

		return res;
	}
};

int GrayCode(){
	Solution a;
	vector<int> b;
	int i;

	b = a.grayCode(2);
	for (i = 0; i < b.size(); i++)
		cout << b[i] << endl;

	cin >> i;
	return 0;
}