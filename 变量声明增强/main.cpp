#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };
	const vector<int>::iterator it = find(v.begin(), v.end(), 2);
	if (it != v.end()) {
		*it = 3;
	}
	cout <<"first line : "<< *it << endl;

	//visual studio 支持C++17 
	/*
	调试->属性->C/C++->语言->C++语言标准->[选择C++2017]
	*/
	if (const vector<int>::iterator it = find(v.begin(), v.end(), 4);it != v.end()) {
		*it = 9;
		cout << "first line : " << *it << endl;
		//这个it的生命周期在 if 中
	}
	

	system("pause");

	return 0;


}