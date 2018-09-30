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
#include<vector>
#include<string>
#include<utility>

using namespace std;

#define _D



#if defined _A
//移动语义
class A
{
public:
	int *pointer;
	A() :pointer(new int(1)) { cout << "constract:" << pointer<<","<<*pointer << endl; }
	//无意义的对象拷贝
	A(A& a) :pointer(new int(*a.pointer)) { cout << "copy:" << pointer << "," << *pointer << endl; }
	A(A&& a) :pointer(a.pointer) { a.pointer = nullptr; cout << "move" << pointer << "," << *pointer << endl; }

	~A() { cout << "destract" << pointer << endl; delete pointer; }
};

//防止编译器优化
A return_value(bool test) {
	A a, b;
	if (test) { 
		return a; 
	}
	else { 
		return b; 
	}
}

int main(int ac, char**av) {
	A obj = return_value(false);
	cout << "obj:" << endl;
	cout << obj.pointer << endl;
	cout << *obj.pointer << endl;
	system("pause");
	return 0;
}




#elif defined _B

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

#elif defined _C

int main()
{
	string str("hello world");
	vector<string> v;

	v.push_back(str);//产生拷贝
	cout <<"not move : "<< str << endl;


	v.push_back(move(str));//str中的值move到vector的成员中 , str被清空 , 不会产生拷贝
	cout <<"move : "<< str << endl;

	system("pause");
	return 0;
}

#elif defined _D
//完美转发
//⼀个声明的右值引⽤其实是⼀个左值。这就为我们进⾏参数转发（传递）造成了问题
#if 0
void reference(int& v) {
	cout << "左值" << endl;
}
void reference(int&& v) {
	cout << "右值" << endl;
}
template<typename T>
void pass(T&& v) {
	cout << "普通传参:";
	reference(v);//始终调用 reference(int&)
}
int main() {
	cout << "传递右值" << endl;
	pass(1);
	cout << "传递左值" << endl;
	int v = 1;

	pass(v);
#if 0
	对于pass(v)⽽⾔， v是⼀个左值，为什么会成功传递给pass(T&&) 呢？
	这是基于引用坍缩规则的：在传统 C++ 中，我们不能够对⼀个引⽤类型继续进⾏引⽤，但 C++ 由
	于右值引⽤的出现⽽放宽了这⼀做法，从⽽产⽣了引⽤坍缩规则，允许我们对引⽤进⾏引⽤，既能左引
	⽤，又能右引⽤
	完美转发就是基于上述规律产⽣的。所谓完美转发，就是为了让我们在传递参数的时候，
	保持原来	的参数类型（左引⽤保持左引⽤，右引⽤保持右引⽤）。为了解决这个问题，
	我们应该使⽤ std::forward	来进⾏参数的转发（传递）
#endif

	system("pause");
	return 0;
}
#else

void reference(int& v) {
	cout << "左值" << endl;
}
void reference(int&& v) {
	cout << "右值" << endl;
}
template<typename T>
void pass(T&& v) {
	std::cout << " 普 通 传 参 :";
	reference(v);
	std::cout << " std :: move 传 参 :";
	reference(std::move(v));
	std::cout << " std :: forward 传 参 :";
	reference(std::forward <T >(v));
}
int main() {
	std::cout << " 传 递 右 值 :" << std::endl;
	pass(1);
	std::cout << " 传 递 左 值 :" << std::endl;
	int v = 1;
	pass(v);

	system("pause");
	return 0;
}


#endif //0

#endif //_A