#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

//委托构造
class Base
{
public:
	Base()
	{
		value1 = 1;
	}
	Base(int i) :Base() {//委托Base构造
		value2 = i;
	}

	int value1;
	int value2;
};

//继承构造
class SubBase :public Base {
public:
	using Base::Base;//继承构造
};

//显示虚函数重载
//override  final 两个关键字

//override : 显式的告知编译器进⾏重载，编译器将检查基函数是否存在这样的虚函数，否则将⽆法通过编译
class Base1 {
public:
	virtual void foo(int) {};
};
class SubBase1 :public Base1 {
public:
	virtual void foo(int) override {}//OK
#if 0
	virtual void foo(float) override {};//NOT OK 父类无此虚函数
#endif
};

//final : 防⽌类被继续继承以及终⽌虚函数继续重载
struct Base2
{
	virtual void foo() final {}
};
struct SubBase21 final :Base2
{};//OK

#if 0
struct SubBase22 :SubBase21
{};//NOT OK , SubBase21已经final

struct SubBase23 :Base2 {
	void foo() {}//NOT OK , foo 已经final
};
#endif

//显示禁用和使用默认函数
class Magic
{
public:
	Magic() = default;//显示声明使用编译器生成的构造函数
	Magic& operator=(const Magic&) = delete;//显示声明拒绝编译器生成构造
	Magic(int num) {};
protected:
private:
};

//强枚举类型
//不能够被隐式的转换为整数，同时也不能够将其与整数数字进⾏⽐较，
//更不可能对不同的枚举类型的枚举值进⾏⽐较。但相同枚举值之间如
//果指定的值相同，那么可以进⾏⽐较
enum class new_enum :unsigned int {
	value1,
	value2,
	value3 = 100,
	value4 = 200
};

//获取枚举的值
template < typename T>
ostream & operator <<(typename enable_if < is_enum <T >::value, ostream >::type & stream, const T& e) {
	return stream << static_cast <typename underlying_type <T >::type>(e);
}


int main(int argc, char** argv)
{
	Base b(1);
	cout << b.value1 << " " << b.value2 << endl;

	SubBase sb(3);
	cout << sb.value1 << " " << sb.value2 << endl;


	system("pause");
	return 0;
}



template <typename Key, typename Value, typename F> 
void update(map<Key,Value>& m, F foo) 
{ 
	// TODO: 
} 
int func() 
{ 
	std::map<std::string, long long	int > m{ {"a", 1}, {"b", 2}, {"c", 3} };
	update(m, [](string key) { return hash<string>{}(key); });
	for (auto&&[key, value] : m) 
		cout << key << ":" << value << endl;
}