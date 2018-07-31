#include<string>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;



template<typename T>
class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	map<int, string> m_map;
	T t;
};

template<typename T>
MyClass<T>::MyClass()
{
	m_map = { make_pair(1,"a"),make_pair(2,"b") };
	for (auto element : m_map)
	{
		cout << element.first << endl << element.second << endl;
	}
}

template<typename T>
MyClass<T>::~MyClass()
{
}

template class MyClass<int>;

void init() {
	MyClass<int> myclass;
}