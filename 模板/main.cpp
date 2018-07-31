#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include "header.h"

using namespace std;

extern template class MyClass<double>;

//外部模板 :	传统 C++ 中 , 只要在每个编译单元（⽂件）中编译的代码中遇到了
//			被完整定义的模板，都会实例化。这就产⽣了重复实例化⽽导致的编译时间的增加。
//				C++11 引⼊了外部模板，扩充了原来的强制编译器在特定位置实例化模板的语法，使我们能
//			够显式的通知编译器何时进⾏模板的实例化

int main1() {
	//MyClass<int> myclass;
	init();

	system("pause");
	return 0;
}
// 连续'>'尖括号
vector<vector<int>> matrix;