#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include "header.h"

using namespace std;

#if 0
template class std::vector <bool >;//强行实例化
extern template class std::vector < double >;//不在该当前编译文件中实例化模板
#endif

//外部模板 :	传统 C++ 中 , 只要在每个编译单元（⽂件）中编译的代码中遇到了
//			被完整定义的模板，都会实例化。这就产⽣了重复实例化⽽导致的编译时间的增加。
//				C++11 引⼊了外部模板，扩充了原来的强制编译器在特定位置实例化模板的语法，使我们能
//			够显式的通知编译器何时进⾏模板的实例化

template<bool T>
class MagicType1
{
public:
	bool magic = T;
protected:
private:
};
//模板~类型:模板是用来产生类型的


//类型别名模板:
template<typename T,typename U>
class MagicType
{
public:
	T dark;
	U magic;
protected:
private:
};
typedef int(*process)(void*);
using NewProcess = int(*)(void*);
template<typename T>
using TrueDarkMagic = MagicType<vector<T>, string>;

//默认模板参数
//参数为int时 , 不用指定参数类型
template<typename T=int,typename U=int>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}

//变长参数模板  C++11
template<typename... T> class Magic;
#if 0
class Magic<int, vector<int>, string> dmm;
#endif
template<typename T,typename... Args> 

//展开变长参数
//1递归模板函数
void print(T t, Args... args) {
	cout << sizeof...(args) << ":" << t << endl;//计算参数个数
	if constexpr (sizeof...(args) > 0)
		print(args...);
}

//2初始化列表展开
template<typename T,typename... Args>
void print1(T value, Args... args)
{
	cout << value << endl;
	return initializer_list<T>
}


int main() {
	//MyClass<int> myclass;
	vector<int> vec;
	vec.push_back(1);

	vector<vector<int>> mat;

	vector<MagicType1<(1 > 2)>> vec1;//Does it mean anything?
	MagicType1<0> mt1;// i don`t know
	vec1.push_back(mt1);
	if (vec1[0].magic==true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	
	TrueDarkMagic<int> tdm;
	tdm.dark.push_back(1);//dark 是一个 vector<int>
	tdm.magic = "magic";//magic 是一个 string

	cout << "============" << endl;
	string str("str000");

	print<string,int,string,string>(str, 2, "hello", " world");
	cout << "============" << endl;



	init();

	system("pause");
	return 0;
}
