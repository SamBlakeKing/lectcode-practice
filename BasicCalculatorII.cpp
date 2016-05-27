#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		vector<int> nums;
		vector<char> signals;
		s.append("$");
		int i = 0,temp;
		char signal;

		//cout << s.size() << endl;

		signals.push_back('$');
		while (i < s.size()){
			//cout <<i<<" "<< s[i] << endl;
			if (' ' == s[i])
				i++;
			else if (level(s[i]) >= 0){
				temp = 0;

				while (level(s[i]) >= 0 || ' ' == s[i]){
					if (' ' != s[i])
						temp = temp * 10 + level(s[i]);
					i++;
				}
				
				nums.push_back(temp);
			}
			else{
				//cout << s[i] << " " << signals.back() << endl;
				while (signals.back() != '$' && level(s[i]) <= level(signals.back())){
					temp = fun(nums[nums.size() - 2], nums[ nums.size() - 1 ], signals[signals.size() - 1]);

					nums.pop_back();
					nums.pop_back();
					signals.pop_back();

					nums.push_back(temp);
				}
				signals.push_back(s[i]);
				i++;
			}
		}

		//for (int j = 0; j < nums.size(); j++)
		//cout << nums[j] << " ";
		//cout << endl;
		//for (int j = 0; j < signals.size(); j++)
		//cout << signals[j] << " ";
		//cout << endl;

		return nums.back();
	}

	int level(char signal){
		if ('$' == signal)
			return -3;
		if ('-' == signal || '+' == signal)
			return -2;
		if ('*' == signal || '/' == signal)
			return -1;
		if (signal >= '0' && signal <= '9')
			return signal - '0';
		/*if (' ' == signal)
			return 10;*/
		return 0;
	}

	int fun(int a, int b, char signal){
		if ('+' == signal)
			return a + b;
		if ('-' == signal)
			return a - b;
		if ('*' == signal)
			return a * b;
		if ('/' == signal){
			if (0 == b)
				return 0;
			return a / b;
		}
		return 0;
	}
};

int main(){
	Solution a;
	string b = "0+0";
	int i;

	cout << a.calculate(b) << endl;
	
	cin >> i;
	return 0;
}