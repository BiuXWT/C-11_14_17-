#include<iostream>
#include<vector>


class Foo	
{
public:
	Foo(int a, int b) :a(a), b(b) {}
	int geta() {
		return a;
	}
	int getb() {
		return b;
	}
protected:
private:
	int a;
	int b;
};
class MagicFoo {
public:

	MagicFoo(std::initializer_list<int> list) {
		for (std::initializer_list<int>::iterator it=list.begin();
			it!=list.end();it++)
		{
			vec.push_back(*it);
		}
	}

	void foo(std::initializer_list<int> list) {
		std::cout << "this is a normal function" << std::endl;
		for (std::initializer_list<int>::iterator it=list.begin();it!=list.end();it++)
		{
			std::cout << *it << std::endl;
		}

	}


	std::vector<int>& getvec() {
		return vec;
	}
private:
	std::vector<int> vec;


};


int main(int ac, char**av) {

	int ar[3] = { 1,2,3 };
	Foo foo(1, 2);
	std::vector<int> vec = { 1,2,3,5,6 };

	std::cout << "arr[0]:" << ar[0] << std::endl;
	std::cout << "foo:" << foo.geta() << "," << foo.getb() << std::endl;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << std::endl;
	}
	
	MagicFoo mf = { 1,2,3,4,5 };

	std::cout << "magicfoo:" << std::endl;
	for (std::vector<int>::iterator it = mf.getvec().begin(); it != mf.getvec().end(); it++) {
		std::cout << *it << std::endl;
	}

	mf.foo({ 1,2,3,4,5,6,7 });




	system("pause");
	return 0;
}