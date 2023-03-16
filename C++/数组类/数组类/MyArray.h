#pragma once

class MyArray {
public:
	MyArray();
	MyArray(int capacity, int val = 0);
	MyArray(const MyArray &arr);
	~MyArray();

	// 重载运算符
	MyArray &operator=(const MyArray &m);
	int &operator[](int index);

	void pushFront(int val);
	void pushBack(int val);
	void popFront();
	void popBack();
	int size();
	int capacity();
	void insert(int pos, int val);
	// 获取指定位置的值
	int &get(int pos);
	void set(int pos, int val);

private:
	int *pArray; // 指向堆空间
	int mSize; // 元素个数
	int mCapacity; // 容量
};