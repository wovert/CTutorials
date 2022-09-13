#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>

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

int main()
{
	test01();
	getchar();
	return 0;
}
