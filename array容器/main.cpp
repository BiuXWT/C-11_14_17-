#include<iostream>
#include<array>
#include<vector>

using namespace std;
//array������ջ�ڴ� , vector�����ڶ��ڴ�

//ʹ��arrayֻ��ָ�����С������
array<int, 4> arr = { 1,2,3,4 };
#if 0
int len = 4;
array<int, len> arr = { 1,2,3,4 };//�����С���������ǳ������ʽ
#endif

//����C���ӿ�
void foo(int *p, int len)
{
	//TODO:
	return;
}
int func() {
	//foo(arr, arr.size());//��֧����ʽת��
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());

	//ʹ��sort����
	sort(arr.begin(), arr.end());
}
