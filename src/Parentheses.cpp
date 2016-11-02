#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct myParenthese{
	char parenthese;
	int left;
	int right;
	int search;
	myParenthese(char a, int b, int c, int d) :parenthese(a), left(b), right(c), search(d){};
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {

		vector<string> result;
		vector<myParenthese> myStack;
		myStack.push_back(myParenthese('\(', 1, 0, 0));
		int current=2;
		int search = 0;
		while (myStack.size()){
			if (current == 2*n + 1){
				char *temp = new char[2*n + 1];
				for (int i = 0; i < myStack.size(); i++)
					temp[i] = myStack[i].parenthese;
					//temp.append(string(myStack[i].parenthese));
				temp[2*n] = '\0';
				result.push_back(string(temp));
				
				myStack.pop_back();
				myParenthese temp_enum = myStack.back();

				current = myStack.size();
				search = temp_enum.search + 1;

				myStack.pop_back();
				delete[]temp;
			}
			else if (0 == search){
				myParenthese temp_enum = myStack.back();

				if (temp_enum.left < n){
					myStack.push_back(myParenthese('\(', temp_enum.left + 1, temp_enum.right, 0));
					current += 1;
					search = 0;
				}
				else
					search = 1;
			}
			else if (1 == search){
				myParenthese temp_enum = myStack.back();

				if (temp_enum.left > temp_enum.right){
					myStack.push_back(myParenthese('\)', temp_enum.left, temp_enum.right + 1, 1));
					current += 1;
					search = 0;
				}
				else
					search = 2;
			}
			else if (2 == search){
				myParenthese temp_enum = myStack.back();

				current -= 1;
				search = temp_enum.search + 1;

				myStack.pop_back();
			}
		}
		return result;
	}
};

int Parentheses(){
	int i;
	Solution a;
	vector<string> b = a.generateParenthesis(1);
	for (i=0; i < b.size(); i++)
		cout << b[i] << endl;

	cin >> i;
	return 1;
}