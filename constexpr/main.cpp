#include<iostream>

using namespace std;

int len_foo() {
	int i = 4;
	return i;
}
constexpr int len_foo_constexpr() {
	int i = 5;
	return i;
}

int main() {

	int tmp = len_foo();
	cout << tmp << endl;
	tmp = len_foo_constexpr();
	cout << tmp << endl;

	system("pause");
	return 0;
}