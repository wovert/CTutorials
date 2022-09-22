#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void test01(void);

// 数组容器

template <class T>
class MyArray {
public:
	T* p;
	int mCapacity;
	int mSize;

public:
	// 保护原生指针，给原生指针取别名
	typedef T* iterator;

	MyArray() {
		mCapacity = 10;
		mSize = 10;
		p = new T[mCapacity];
		for (int i = 0; i < mCapacity; i++) {
			p[i] = i + 1;
		}
	}

	// 提供迭代器，开始位置的迭代器
	T* begin() {
		return p;
	}

	// 返回结束位置的迭代器
	T* end() {
		return p + mSize;
	}

};

// 算法
template <class T>
void printArray(T begin, T end) {

	for (; begin != end; ++begin) {
		cout << *begin << " ";
	}
}


void test01(void) {
	MyArray<int> arr;
	//  获取容器提供的迭代器
	MyArray<int>::iterator begin = arr.begin();

	// 获取容器提供的结束位置迭代器
	MyArray<int>::iterator end = arr.end();

	printArray(begin, end);
}


void print(int val) {
	cout << val << " ";
}

void test02() {
	// 容器
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 获取开始位置的迭代器
	vector<int>::iterator begin = v.begin();
	
	// 获取结束位置的迭代器
	vector<int>::iterator end = v.end();

	// 遍历算法
	for_each(begin, end, print);
	cout << endl;
}

int main()
{
	//test01();
	test02();
	getchar();
	return 0;
}
