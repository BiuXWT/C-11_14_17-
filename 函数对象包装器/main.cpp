#include<iostream>
#include<functional>
using namespace std;

int foo(int value)
{
	return value;
}


//std::bind  std::placeholders
int foo2(int a, int b, int c) {
	cout<<a<<"  " <<b<<"  "<<c<<endl;
	return 0;
}

int param_bind()
{
	//把参数1,2绑定到函数foo2上 , 并对第一个参数进行占位
	auto bindfoo = bind(foo2, placeholders::_1, 1, 2);
	//调用时提供第一个参数就OK
	bindfoo(1);
	return 0;
}

int main() {
	function<int(int)> func = foo;
	int important = 10;
	function<int(int)> func2 = [&](int value2)->int {
		return 1 + value2 + important;
	};
	cout << func(100) << endl;
	cout << func2(100) << endl;

	param_bind();

	system("pause");
	return 0;
}
