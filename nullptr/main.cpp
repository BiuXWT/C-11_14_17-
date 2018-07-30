#include<iostream>
using namespace std;

void func(int i) {
	cout << "call func(int i)\n";
}
void func(int *i) {
	cout << "call func(int *i)\n";
}

int main() {

	func(NULL);//NULL explain as 0 , an integer
	cout << "=======\n";
	func(nullptr);

	system("pause");

	return 0;

}