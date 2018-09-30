#include<iostream>
#include<array>
#include<vector>

using namespace std;
//array保存在栈内存 , vector保存在堆内存

//使用array只需指定其大小和类型
array<int, 4> arr = { 1,2,3,4 };
#if 0
int len = 4;
array<int, len> arr = { 1,2,3,4 };//数组大小参数必须是常量表达式
#endif

//兼容C风格接口
void foo(int *p, int len)
{
	//TODO:
	return;
}
int func() {
	//foo(arr, arr.size());//不支持隐式转换
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());

	//使用sort排序
	sort(arr.begin(), arr.end());
}
