#include <iostream>
#include <string>
using namespace std;
std::tuple<int, double, string> f() {

	return make_tuple(1, 2.2, "oops!");
}//ʹ��tuple����һ��Ԫ�� , ���������������ֵ

int main() {

	auto [a, b, c] = f(); //auto  �����Ƶ�

	cout << a << " " << b << " " << c << endl;

	system("pause");
}