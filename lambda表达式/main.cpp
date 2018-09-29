#include<iostream>

using namespace std;

//[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型{ 函数体 }

//lambda 表达式内部函数体在默认情况下是不能够
//使⽤函数体外部的变量的，这时候捕获列表可以起到传递外部数据的作⽤
#if 0
•[] 空捕获列表
•[name1, name2, . . .] 捕获⼀系列变量
•[&] 引⽤捕获, 让编译器⾃⾏推导捕获列表
•[=] 值捕获, 让编译器执⾏推导应⽤列表
#endif

//捕获列表
void lambda_func1() {
	// 1. lambda表达式的 值捕获
	int value_1 = 1;
	auto copy_value_1 = [value_1] {return value_1; };

	value_1 = 100;
	auto stored_value1 = copy_value_1();//在创建lambda表达式时 , 值就被保存

	cout << value_1 << endl;
	cout << stored_value1 << endl;
}

void lambda_func2() {
	// 2. 引用捕获
	int value_2 = 2;
	auto copy_value_2 = [&value_2] { return value_2; };

	value_2 = 100;
	auto stored_value_2 = copy_value_2();//创建lambda表达式时 , 保存的引用

	cout << value_2 << endl;
	cout << stored_value_2 << endl;
}

void lambda_func3() {
	// 3. 隐式捕获 , 把捕获列表的填充交给编译器
	// 在捕获列表中写一个 & 或者 = , 向编译器声明采用引用捕获或者值捕获

}
//泛型lambda
void lambda_func4() {
	auto add = [](auto x, auto y) {
		return x + y;
	};
	cout << add(1, 2) << endl;
	cout << add(1.1, 2.2) << endl;

}

//函数对象包装器  
//Lambda表达式本质是一个函数对象 , Lambda表达式的捕获列表为空时可作为函数指针
using foo = void(int);
void functional(foo f) {
	f(1);
}
int main() {
	auto f = [](int value) {
		cout << value << endl;
	};
	functional(f);//函数指针调用
	f(1);//表达式调用


	system("pause");
	return 0;
}



int main1() {
	lambda_func1();
	lambda_func2();
	lambda_func3();
	lambda_func4();

	system("pause");
	return 0;
}