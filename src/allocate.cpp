#include <memory>
#include <iostream>
#include <string>
using namespace std;
int allocate(){
	/*
	int temp;
	shared_ptr<int> p = make_shared<int>(42);
	weak_ptr<int> p1(p);
	if (p1.lock())
		cout << "shared_ptr:" << *p << ";weak_ptr:" << *p1.lock() << endl;
	p = nullptr;
	if (!p1.lock())
		cout <<"the p1 is null"<< endl;
	cin >> temp;
	return 1;
	*/
	int temp;
	allocator<string> alloc;
	auto p = alloc.allocate(10);
	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");
	q = p;
	cout << p[0] << endl;
	cout << p[1] << endl;
	cout << p[2] << endl;
	cin >> temp;
	return 1;
}