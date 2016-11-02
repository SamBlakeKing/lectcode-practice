#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class sale_data{
public:
	string bookNO;
	unsigned int units_sold=0;
	double revenue=0.0;
	string isbn() const { return bookNO; }
	sale_data &combine(const sale_data &b);
	double avg_price()const;
	//sale_data add(const sale_data&, const sale_data&);
	//ostream &print(ostream &, const sale_data&);
	//istream &read(istream &, sale_data&);
	sale_data() = default;
	sale_data(const string a) :bookNO(a){};
	sale_data(const string a, unsigned int b, double p) :bookNO(a), units_sold(b), revenue(b*p){};
};

sale_data& sale_data::combine(const sale_data& b){
	units_sold += b.units_sold;
	revenue += b.revenue;
	return *this;
}
double sale_data::avg_price()const{
	if (units_sold > 0)
		return revenue / units_sold;
	return 0;
}
sale_data add(const sale_data &a, const sale_data &b){
	sale_data rtn = a;
	rtn.combine(b);
	return rtn;
}
ostream& print(ostream& o, const sale_data& a){
	o << a.bookNO << " " << a.revenue << " " << a.avg_price();
	return o;
}
istream& read(istream& i, sale_data& a){
	double price = 0;
	i >> a.bookNO >> a.units_sold >> price;
	a.revenue = a.units_sold * price;
	return i;
}

int test(){
	int i;
	sale_data total;
	ofstream outfile("result.txt");
	if (read(cin, total)){
		sale_data trans;
		while (read(cin, trans)){
			if (trans.isbn() == total.isbn()){
				total.combine(trans);
			}
			else{
				print(outfile, total) << endl;
				total = trans;
			}
		}
		print(outfile, total) << endl;
	}
	else{
		cout << "No data!" << endl;
	}
	cin >> i;
	return 0;
}