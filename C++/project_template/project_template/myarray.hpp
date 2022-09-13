#pragma once
#include <iostream>
#include <ostream>
using namespace std;

template <typename Item>
class MyArray {
	friend ostream &operator<<<>(ostream &, const MyArray<Item> &);
	int m_capacity; // 总量
	int m_size; // 元素个数
	Item *m_addr; // 首元素地址
	void checkIndex(int);
public:
	MyArray();
	MyArray(int capacity);
	~MyArray();

	void pushBack(Item data);
	void remove(int data);
	Item getData(int pos);
	void setData(int pos, Item data);
	int getCapacity(void);
	int getSize(void);
	Item operator[](int index);
};


template <typename Item>
MyArray<Item>::MyArray() {
	this->m_capacity = 100;
	this->m_size = 0;
	// 根据容量给数组申请空间
	this->m_addr = new Item[this->m_capacity];
}


template <typename Item>
MyArray<Item>::MyArray(int capacity) {
	this->m_capacity = capacity;
	this->m_size = 0;
	// 根据容量给数组申请空间
	this->m_addr = new Item[this->m_capacity];
}

template <typename Item>
MyArray<Item>::~MyArray() {
	if (this->m_addr != NULL) {
		delete[] this->m_addr;
		this->m_addr = NULL;
	}
}

template <typename Item>
void MyArray<Item>::checkIndex(int index) {
	if (index < 0 || index >= m_size) {
		throw "数组下标越界";
	}
}

template <typename Item>
void MyArray<Item>::pushBack(Item data) {
	//checkIndex(index);
	//if (this->m_size >= this->m_capacity) {
	//	cout << "array is full" << endl;
	//	// Extend space
	//	// 1. register new space
	//	// 2. copy data from old space data to new space data
	//	// 3. free old space
	//}
	this->m_addr[this->m_size] = data;
	this->m_size++;
}

template <typename Item>
void MyArray<Item>::remove(int index) {
	checkIndex(index);

}


template <typename Item>
Item MyArray<Item>::operator[](int index) {
	return getData(index);
}

template <typename Item>
Item MyArray<Item>::getData(int pos) {
	if (pos >= this->m_size || pos < 0) {
		cout << "Not found position:" << pos << endl;
		throw "Array index out bounds";
		// return Item;
	}
	return m_addr[pos];
}

template <typename Item>
void MyArray<Item>::setData(int pos, Item data) {
	if (pos >= this->m_size || pos < 0) {
		cout << "Not found position:" << pos << endl;
		return;
	}
	this->m_addr[pos] = data;
}

template <typename Item>
int MyArray<Item>::getCapacity(void) {
	return this->m_capacity;
}

template <typename Item>
int MyArray<Item>::getSize(void) {
	return this->m_size;
}

template <typename Item>
ostream &operator<<<>(ostream &cout, const MyArray<Item> &arr) {
	cout << "[";
	for (int i = 0; i < arr.m_size; i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << arr.m_addr[i];
	}
	return cout << "]";
}