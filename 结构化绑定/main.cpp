#include <iostream>
#include <string>
using namespace std;
std::tuple<int, double, string> f() {

	return make_tuple(1, 2.2, "oops!");
}//使用tuple构造一个元组 , 进而囊括多个返回值

int main() {

	auto [a, b, c] = f(); //auto  类型推导

	cout << a << " " << b << " " << c << endl;

	system("pause");
}