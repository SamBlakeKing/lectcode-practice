#include <iostream>
#include <regex>

using namespace std;

int main(){
	const char *reg_esp = "(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)(\\\/(\\d+))?";
	regex rgx(reg_esp);
	cmatch match;
	int i;

	const char *target = "255.255.255.255";
	if (regex_search(target, match, rgx)){
		int n = match.size();

		for (i = 0; i < n; i++){
			if ("" == match.str(i + 1))
				cout << "the result ";
			cout << atol(match.str(i+1).c_str()) << endl;
		}
	}

	cin >> i;
	return 0;
}