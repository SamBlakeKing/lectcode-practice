//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//const char MASK[9] = { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff};
//
//struct IpData{
//	bool deny;
//	char IP[4];
//	char ip_mask[4];
//	IpData(){};
//	IpData(string a, string b){
//		int mask = 32;
//
//		if ("allow" == a)
//			deny = false;
//		else
//			deny = true;
//		int start = 0;
//		int i = 0, j;
//		for (j = 0; j < 4; j++){
//			int sum = 0;
//			while ('\0' != b[i] && '.' != b[i] && '\/' != b[i]){
//				sum = sum * 10 + (b[i++] - '0');
//			}
//			if ('.' == b[i])
//				i++;
//			IP[j] = sum;
//			//cout << sum << endl;
//		}
//		if ('\/' == b[i]){
//			i++;
//			int sum = 0;
//			while ('\0' != b[i]){
//				sum = sum * 10 + (b[i++] - '0');
//			}
//			mask = sum;
//			//cout << sum << endl;
//		}
//		//cout << mask << endl;
//		if (mask >= 0 && mask <= 8){
//			IP[0] = IP[0] & MASK[mask];
//			IP[1] = IP[1] & MASK[0];
//			IP[2] = IP[2] & MASK[0];
//			IP[3] = IP[3] & MASK[0];
//
//			ip_mask[0] = MASK[mask];
//			ip_mask[1] = MASK[0];
//			ip_mask[2] = MASK[0];
//			ip_mask[3] = MASK[0];
//		}
//		else if (mask >= 9 && mask <= 16){
//			IP[1] = IP[1] & MASK[mask - 8];
//			IP[2] = IP[2] & MASK[0];
//			IP[3] = IP[3] & MASK[0];
//
//			ip_mask[0] = MASK[8];
//			ip_mask[1] = MASK[mask - 8];
//			ip_mask[2] = MASK[0];
//			ip_mask[3] = MASK[0];
//		}
//		else if (mask >= 17 && mask <= 24){
//			IP[2] = IP[2] & MASK[mask -16];
//			IP[3] = IP[3] & MASK[0];
//
//			ip_mask[0] = MASK[8];
//			ip_mask[1] = MASK[8];
//			ip_mask[2] = MASK[mask - 16];
//			ip_mask[3] = MASK[0];
//		}
//		else if (mask >= 25 && mask <= 32){
//			IP[3] = IP[3] & MASK[mask - 24];
//
//			ip_mask[0] = MASK[8];
//			ip_mask[1] = MASK[8];
//			ip_mask[2] = MASK[8];
//			ip_mask[3] = MASK[mask - 24];
//		}
//		//cout << IP[0] + '0' << IP[1] + '0' << IP[2] + '0' << IP[3] + '0' << endl;
//	}
//	bool check(char *p){
//		int i = 0;
//		for (i = 0; i < 4; i++){
//			//cout << i << " " << IP[i] + '0' << " " << p[i] + '0' << " " << (IP[i] & p[i]) << endl;
//			/*if (IP[i] != (IP[i] & p[i]))
//				return false;*/
//			if ( IP[i] != (p[i] & ip_mask[i]))
//				return false;
//		}
//		return true;
//	}
//};
//
//int main(void){
//	fstream file("D:\\data.txt");
//
//	IpData *data,*temp;
//	unsigned int m, n, i;
//	string temp_ip;
//	char temp_IP[4];
//	unsigned int k = 0, j;
//	unsigned sum;
//
//	file >> m >> n;
//
//	data = new IpData[m];
//	bool *q = new bool[n];
//	for (i = 0; i < m; i++){
//		string temp1, temp2;
//		file >> temp1 >> temp2;
//
//		//cout << temp1 << temp2<<endl;
//		
//		temp = new IpData(temp1, temp2);
//		data[i].deny = temp->deny;
//		for (unsigned int j = 0; j < 4; j++){
//			data[i].IP[j] = temp->IP[j];
//			data[i].ip_mask[j] = temp->ip_mask[j];
//		}
//		delete temp;
//	}
//	for (i = 0; i < n; i++){
//		file >> temp_ip;
//
//		k = 0;
//		for (j = 0; j < 4; j++){
//			sum = 0;
//			while ('\0' != temp_ip[k] && '.' != temp_ip[k]){
//				sum = sum * 10 + (temp_ip[k++] - '0');
//			}
//			if ('.' == temp_ip[k])
//				k++;
//			temp_IP[j] = sum;
//		}
//
//		for (j = 0; j < m;j++)
//			if (data[j].check(temp_IP)){
//				if (data[j].deny)
//					cout << "NO" << endl;
//				else
//					cout << "YES" << endl;
//				break;
//			}
//		if (j == m)
//			cout << "YES" << endl;
//	}
//
//	/*for (i = 0; i < m; i++){
//		if (data[i].deny)
//			cout << "yes ";
//		else
//			cout << "no";
//		cout << data[i].IP[0] + '0' << data[i].IP[1] + '0' << data[i].IP[2] + '0' << data[i].IP[3] + '0' << endl;
//	}*/
//
//	/*for (i = 0; i < n; i++)
//		if (q[i])
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;*/
//	delete[]data;
//	delete[]q;
//
//	cin >> i;
//	return 0;
//}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <regex>
//
//using namespace std;
//
//const unsigned long MASK[9] = { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };
//
//struct IpData{
//	bool deny;
//	unsigned long myIP;
//	unsigned long myMask;
//
//	IpData(){};
//	void InsertData(string a, string b){
//		int mask = 32;
//		int i = 0, j;
//		unsigned long sum = 0;
//		myIP = 0;
//
//		const char *reg_esp = "(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)(\\\/(\\d+))?";
//		regex rgx(reg_esp);
//		cmatch match;
//
//		if ("allow" == a)
//			deny = false;
//		else
//			deny = true;
//
//		if (regex_search(b.c_str(), match, rgx)){
//			for (j = 0; j < 4; j++){
//				myIP = myIP | ( ((unsigned long)atol(match.str(j + 1).c_str())) << (24 - j * 8));
//			}
//			mask = (unsigned long )atol(match.str(6).c_str());
//			if ("" == match.str(5))
//				mask = 32;
//		}
//
//		myMask = 0;
//		if (mask >= 0 && mask <= 8){
//			myMask = MASK[mask] << 24;
//			myIP = myMask & myIP;
//		}
//		else if (mask >= 9 && mask <= 16){
//			myMask = MASK[8] << 24;
//			myMask = myMask | MASK[mask - 8] << 16;
//
//			myIP = myMask & myIP;
//		}
//		else if (mask >= 17 && mask <= 24){
//			myMask = MASK[8] << 24 | MASK[8] << 16;
//			myMask = myMask | MASK[mask - 16] << 8;
//
//			myIP = myMask & myIP;
//		}
//		else if (mask >= 25 && mask <= 32){
//			myMask = MASK[8] << 24 | MASK[8] << 16 | MASK[8] << 8;
//			myMask = myMask | MASK[mask - 24];
//
//			myIP = myMask & myIP;
//		}
//	}
//	bool check(unsigned long p){
//		if (myIP == (p & myMask))
//			return true;
//		return false;
//	}
//};
//
//int main(void){
//	fstream file("D:\\data.txt");
//
//	IpData *data;
//	unsigned int m, n, i;
//	string temp_ip;
//	unsigned long temp_IP;
//	unsigned int k = 0, j;
//	unsigned sum;
//	const char *reg_esp = "(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)";
//	regex rgx(reg_esp);
//	cmatch match;
//
//	file >> m >> n;
//
//	data = new IpData[m];
//	for (i = 0; i < m; i++){
//		string temp1, temp2;
//		file >> temp1 >> temp2;
//
//		data[i].InsertData(temp1, temp2);
//	}
//	for (i = 0; i < n; i++){
//		file >> temp_ip;
//
//		k = 0;
//		temp_IP = 0;
//		regex_search(temp_ip.c_str(), match, rgx);
//		for (j = 0; j < 4; j++){
//			temp_IP = temp_IP | ( ( (unsigned long)atol(match.str(j+1).c_str()) ) << (24 - j * 8));
//		}
//
//		for (j = 0; j < m; j++)
//			if (data[j].check(temp_IP)){
//				if (data[j].deny)
//					cout << "NO" << endl;
//				else
//					cout << "YES" << endl;
//				break;
//			}
//		if (j == m)
//			cout << "YES" << endl;
//	}
//	delete[]data;
//
//	cin >> i;
//	return 0;
//}


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const unsigned long MASK[9] = { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };

struct IpData{
	bool deny;
	unsigned long myIP;
	unsigned long myMask;

	IpData(){};
	IpData(string a, string b){
		int mask = 32;
		int i = 0, j;
		unsigned long sum = 0;
		myIP = 0;

		if ("allow" == a)
			deny = false;
		else
			deny = true;

		for (j = 0; j < 4; j++){
			sum = 0;
			while ('\0' != b[i] && '.' != b[i] && '\/' != b[i]){
				sum = sum * 10 + (b[i++] - '0');
			}
			if ('.' == b[i])
				i++;
			myIP = myIP | (sum << (24 - j * 8));
		}


		if ('\/' == b[i]){
			i++;
			sum = 0;
			while ('\0' != b[i]){
				sum = sum * 10 + (b[i++] - '0');
			}
			mask = sum;
		}

		myMask = 0;
		if (mask >= 0 && mask <= 8){
			myMask = MASK[mask] << 24;
			myIP = myMask & myIP;
		}
		else if (mask >= 9 && mask <= 16){
			myMask = MASK[8] << 24;
			myMask = myMask | MASK[mask - 8] << 16;

			myIP = myMask & myIP;
		}
		else if (mask >= 17 && mask <= 24){
			myMask = MASK[8] << 24 | MASK[8] << 16;
			myMask = myMask | MASK[mask - 16] << 8;

			myIP = myMask & myIP;
		}
		else if (mask >= 25 && mask <= 32){
			myMask = MASK[8] << 24 | MASK[8] << 16 | MASK[8] << 8;
			myMask = myMask | MASK[mask - 24];

			myIP = myMask & myIP;
		}
		//cout << hex << myIP << " " << myMask << dec << endl;
		//cout << IP[0] + '0' << IP[1] + '0' << IP[2] + '0' << IP[3] + '0' << endl;
	}
	bool check(unsigned long p){
		//cout << hex << myIP << " " << p << dec << endl;
		if (myIP == (p & myMask))
			return true;
		return false;
	}
};

int IP_deny(void){
	IpData *data, *temp;
	unsigned int m, n, i;
	string temp_ip;
	unsigned long temp_IP;
	unsigned int k = 0, j;
	unsigned sum;

	cin >> m >> n;

	data = new IpData[m];
	for (i = 0; i < m; i++){
		string temp1, temp2;
		cin >> temp1 >> temp2;

		temp = new IpData(temp1, temp2);
		data[i].deny = temp->deny;
		for (unsigned int j = 0; j < 4; j++){
			data[i].myIP = temp->myIP;
			data[i].myMask = temp->myMask;
		}
		delete temp;
	}
	for (i = 0; i < n; i++){
		cin >> temp_ip;

		k = 0;
		temp_IP = 0;
		for (j = 0; j < 4; j++){
			sum = 0;
			while ('\0' != temp_ip[k] && '.' != temp_ip[k]){
				sum = sum * 10 + (temp_ip[k++] - '0');
			}
			if ('.' == temp_ip[k])
				k++;
			temp_IP = temp_IP | (sum << (24 - j * 8));
		}

		for (j = 0; j < m; j++)
			if (data[j].check(temp_IP)){
				if (data[j].deny)
					cout << "NO" << endl;
				else
					cout << "YES" << endl;
				break;
			}
		if (j == m)
			cout << "YES" << endl;
	}
	delete[]data;

	return 0;
}