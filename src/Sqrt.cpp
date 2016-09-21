#include <iostream>
#include "math.h"

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		unsigned long begin = 0, end = x;
		unsigned long median;
		while (begin < end){
			median = (begin + end) / 2;
			if (x == median * median)
				return median;
			else if (median * median > x)
				end = median - 1;
			else
				begin = median + 1;
		}

		median = (begin + end) / 2;
		if (median * median <= x)
			return median;
		else
			return median - 1;
	}
};

int main(){
	Solution a;
	int i=0;
	//for (i = 0; i < 10; i++)
		cout << "the sqort of" << i << " is " << a.mySqrt(2147395599) << endl;

	cin >> i;
	return 0;
}