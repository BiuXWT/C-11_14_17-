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

	//visual studio ֧��C++17 
	/*
	����->����->C/C++->����->C++���Ա�׼->[ѡ��C++2017]
	*/
	if (const vector<int>::iterator it = find(v.begin(), v.end(), 4);it != v.end()) {
		*it = 9;
		cout << "first line : " << *it << endl;
		//���it������������ if ��
	}
	

	system("pause");

	return 0;


}