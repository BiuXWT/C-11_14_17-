//左值 ; 右值:纯右值,将亡值,右值
//左值 (lvalue, left value)，顾名思义就是赋值符号左边的值。
//右值 (rvalue, right value)，指表达式结束后就不再存在的临时对象。
//将亡值 : 即将被销毁、却能够被移动的值。

//右值引用和左值引用
//需要拿到一个将亡值 , 需要使用右值引用的声明: T&& ,T是类型 .
//右值引用使临时值的生命周期延长 , 只要变量存在 , 将亡值将一
//直存在 , C++11 提供std::move方法 , 将左值参数无条件转换为右值


//移动语义
//传统C++实现对资源的移动 , 调用者需要先复制 , 再析构 . 造成了大量数据拷贝 ,
//浪费空间 时间 . 右值引用则区分了'移动'和'拷贝'


#include<iostream>
#include<string>

using namespace std;

void reference(string& str)
{
	cout << "reference" << endl;
	cout << "左值" << str << endl;
}
void reference(string&& str)
{
	cout << "reference" << endl;
	cout << "右值" << str << endl;
}

int main(int ac, char**av)
{
	//int &i = 1;//常规引用 , 不能引用右值变量
	int &&i = 1;//右值引用 , 可以引用右值变量
	i = 5;//且能修改值

	string lv1 = "string,";//lv1 是左值
	//string&& r1=s1;//非法 , 右值引用不能引用左值
	string&& rv1 = move(lv1);
	cout << rv1 << endl;

	reference(rv1);
	
	const string& lv2 = lv1 + lv1;//合法 , 常量左值引用能延长临时变量的生命周期
	//lv2+="Test"; // 非法 , 引用的右值无法被修改
	cout << lv2 << endl;


	string&& rv2 = lv1 + lv2;//OK , 右值引用延长临时对象生命周期
	rv2 += "Test";//OK , 非常量引用可修改临时变量的值
	cout << rv2 << endl;

	reference(rv2);//rv2 虽然引⽤了⼀个右值，但由于它是⼀个引⽤，所以 rv2 依然是⼀个左值


	system("pause");

	return 0;
}