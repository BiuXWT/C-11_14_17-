#include<iostream>
#include<string>
#include<initializer_list>
#include<vector>


using namespace std;

//auto 和 decltype  (declare type) 类型推导 

//在 C++17 中对 auto 进行了语义变更

//auto 不能用于传参

class MagicFoo {
public:
	MagicFoo() {
		cout << "无参构造" << endl;
	}
	MagicFoo(initializer_list<int> list) {
		cout << "list 构造" << endl;
		for (auto it=list.begin();it!=list.end();it++)
		{
			vec.push_back(*it);
		}
	}
	auto& getvec() {
		return vec;
	}
private:
	vector<int> vec;
};

auto var1 = 1;
auto var2 = 2;
auto var3 = 3;
decltype(var3 + var1) var4;

#if 0
template<typename T,typename U>
decltype(t+u) add(T t, U u){
	return t + u;
}
//但事实上这样的写法并不能通过编译。
//这是因为在编译器读到 decltype(x+y) 时， x 和 y 尚未被定义
#endif


template<typename T, typename U>
auto add2(T t, U u) ->decltype(t+u) {
	return t + u;
}
//尾返回类型（trailing return type），
//利⽤ auto 关键字将返回类型后置

template<typename T, typename U>
auto add3(T t, U u) {
	return t + u;
}


//decltype(auto)
//参数转发 , 语言运行时强化 , 用于对转发函数或封装的返回类型进行推导
string lookup1() { string str("hello"); return str; }
string& lookup2() { string str("hello"); return str; }
decltype(auto) lookup_a_string1() {
	return lookup1();
}

decltype(auto) lookup_a_string2() {
	return lookup2();
}


int main() {
	MagicFoo mf = { 1,2,3,4,5 };
	vector<int> &v = mf.getvec();

	auto mfit = mf.getvec().begin();
	auto vit = v.begin();
	//cout << mfit << endl;
	//cout << vit << endl;
	printf("%p\n", &*mfit);
	printf("%p\n", &*vit);

	cout << "===============\n";
	for (auto it=v.begin();it!=v.end();it++)
	{
		cout << *it << endl;
	}


	if (is_same<decltype(var4),int>::value)
	{
		cout << "type var4 == int" << endl;
	}

	//add(1, 2);
	cout << add2(1, 2) << endl;
	cout << add3(1, 2) << endl;


	system("pause");
}