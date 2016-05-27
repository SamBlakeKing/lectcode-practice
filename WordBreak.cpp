#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int max = 0;
		int i;

		/*for (auto begin = wordDict.begin(); begin != wordDict.end(); begin++)
			cout << (*begin).c_str() << endl;*/

		for (auto begin = wordDict.begin(); begin != wordDict.end(); begin++)
			if ((*begin).size()>max)
				max = (*begin).size();
		//cout << max << endl;

		return fun(s, 0, wordDict, max);
	}

	bool fun(string &s, int index, unordered_set<string>& wordDict, int max){
		//cout << index << endl;
		if (index == s.size())
			return true;
		int i;

		for (i = 1; i <= max && i + index <= s.size(); i++){

			//cout << s.substr(index, i).c_str() << endl;
			if ( wordDict.end() == wordDict.find(s.substr(index, i)) )
				continue;

			//cout << (wordDict.find(s.substr(index, i)))->c_str() << endl;
			if (fun(s, i + index, wordDict, max))
				return true;
		}

		return false;
	}
};

int main(){
	Solution a;
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	int i;

	if (a.wordBreak(s, wordDict))
		cout << "the result is true;" << endl;

	cin >> i;
	return 0;
}