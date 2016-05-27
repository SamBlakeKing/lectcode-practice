#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Word{
	int num;
	unsigned long word;
	Word(int a, unsigned long b) :num(a), word(b){};
};

class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.size() <= 1)
			return 0;

		string temp;
		unsigned long temp_word;
		vector<Word> myWords;
		int result = 0, i, j;

		unsigned long character[26];
		for (i = 0; i < 26; i++){
			character[i] = 1 << i;
			//cout << character[i] << endl;
		}

		for (i = 0; i < words.size(); i++){
			temp = words[i];
			temp_word = 0;
			for (j = 0; j < temp.size(); j++){
				temp_word = temp_word | character[temp[j] - 'a'];
			}
			//cout << temp << " " << hex << temp_word << dec << endl;
			myWords.push_back(Word(temp.size(), temp_word));
		}
		for (i = 0; i < myWords.size() - 1; i++)
			for (j = i + 1; j < myWords.size(); j++)
				if (0 == (myWords[i].word & myWords[j].word))
					if (myWords[i].num * myWords[j].num > result)
						result = myWords[i].num * myWords[j].num;
		return result;
	}
};

int main(){
	int i;
	Solution a;
	vector<string> b{ "a", "aa", "aaa", "aaaa" };
	cout << a.maxProduct(b) << endl;

	cin >> i;
	return 0;
}