#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
//for example: "ACGAATTCCG".When studying DNA, 
//it is sometimes useful to identify repeated sequences within the DNA.
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.

//Best Answer:
//There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.
//A is 0x41, C is 0x43, G is 0x47, T is 0x54
//We can simply use s[i] & 7 to get the last digit which are just the last 3 bits

//vector<string> findRepeatedDnaSequences(string s) {
//	unordered_map<int, int> m;
//	vector<string> r;
//	for (int t = 0, i = 0; i < s.size(); i++)
//		if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
//			r.push_back(s.substr(i - 9, 10));
//	return r;
//}

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		vector<string> temp;
		string temp_sub;
		int i;

		if (s.size() < 10)
			return result;
		
		for (i = 0; i < s.size() - 9; i++){
			temp.push_back(s.substr(i, 10));
			//cout << temp.back() << endl;
		}

		sort(temp.begin(), temp.end());
		temp_sub = "";
		for (i = 1; i < temp.size(); i++){
			//cout << temp[i] << endl;
			if (temp[i] == temp[i - 1] && temp_sub != temp[i]){
				temp_sub = temp[i];
				result.push_back(temp_sub);
			}
		}

		return result;
	}
};

int main(){
	vector<string> result;
	Solution a;
	int i;
	string temp = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

	result = a.findRepeatedDnaSequences(temp);
	for (i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	cin >> i;
	return 0;
}