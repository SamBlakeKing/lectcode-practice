#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
struct person{
	string name;
	vector<string> phones;
};

int mStream(){
	vector<person> persons;
	string line;
	ifstream in("test.txt");
	while(getline(in, line)){
		//cout << line << endl;
		person one;
		string temp;
		istringstream istring(line);
		istring >> temp;
		one.name = temp;
		while (istring >> temp)
			one.phones.push_back(temp);
		persons.push_back(one);
	}
	for (auto one : persons){
		cout << one.name<<" ";
		for (auto phone : one.phones)
			cout << phone << " ";
		cout << endl;
	}
	cin >> line;
	return 1;
}