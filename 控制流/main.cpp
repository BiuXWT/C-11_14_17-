#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;


//#define IF_CONSTEXPR
#define RANGE_BASED_FOR_LOOP

#if defined(IF_CONSTEXPR)

template<typename T>
auto print_type_info(const T& t) {
	if constexpr(is_integral<T>::value)
	{
		return t + 1;
	}
	else {
		return t + 0.001;
	}
}


int main() {
	cout << print_type_info(5) << endl;
	cout << print_type_info(3.1) << endl;

	system("pause");
	return 0;
}


#elif defined(RANGE_BASED_FOR_LOOP)

int main() {
	vector<int> vec = { 1,2,3,4,5 };
	if (auto it = find(vec.begin(), vec.end(), 3);it!=vec.end())
	{
		*it = 4;
	}
	for (auto element : vec) {
		cout << element << endl;
	}
	for (auto &element : vec) {
		element += 1;
	}
	cout << "=======\n";
	for (auto element : vec) {
		cout << element << endl;
	}


	cout << "++++++++++++" << endl;

	map<int, string> m = { make_pair(1,"a"),make_pair(2,"b"),make_pair(3,"c"),make_pair(4,"d") };

	for (auto element:m)
	{
		cout << element.first << " " << element.second << endl;
	}
	system("pause");
	return 0;

}




#endif // IF_CONSTEXPR
