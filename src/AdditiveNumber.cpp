#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num){
		if (num.size() < 3)
			return false;

		unsigned long length = (num.size()-1) / 2;
		unsigned long i, j,end;
		float temp_a, temp_b, temp_c;
		
		for (i = 1; i <= length; i++)
			for (j = 1; j <= min((num.size() - i) / 2, (num.size() - 2 * i)); j++){//min((num.size() - i)/2,(num.size() - 2*i))
				temp_a = atol(num.substr(0, i).c_str());
				temp_b = atol(num.substr(i, j).c_str());
				temp_c = temp_a + temp_b;

				if (i != fun(temp_a) || j != fun(temp_b))
					break;

				end = i + j;
				/*if (temp_c > atol(num.substr(end, fun(temp_c)).c_str()))
					cout << num.size()<<" "<< i << " " << end << " " << temp_c << " " << num.substr(end, fun(temp_c)).c_str() << " " << (temp_c == atol(num.substr(end, fun(temp_c)).c_str())) << endl;*/
				while (end + fun(temp_c) <= num.size() && temp_c == atol(num.substr(end, fun(temp_c)).c_str()) ){
					end +=fun(temp_c);
					temp_a = temp_b;
					temp_b = temp_c;
					temp_c = temp_a + temp_b;

					if (end == num.size())
						return true;
				}
		}
		return false;
	}

	int fun(int num){
		int result=1;
		while (num / 10){
			result++;
			num = num / 10;
		}

		return result;
	}
};

int AdditiveNumber(){
	//int i = 123;
	//string temp ="dfasfaf";
	////temp = to_string(i);
	//cout << temp.substr(0,1) << endl;
	int i;
	Solution a;
	//string b = "121474836472147483648";
	string b = "121474836472147483648";
	//cout << b.substr(1, 3) <<" "<<atoi(b.substr(7,10).c_str())<< endl;
	if (a.isAdditiveNumber(b))
		cout << "the is additive number." << endl;

	cin >> i;
	return 0;
}