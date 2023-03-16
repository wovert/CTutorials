#include <iostream>

#include "MyArray.h";

using namespace std;

void printMyArray(MyArray &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void demo01() {
	MyArray arr(20, 1);
	printMyArray(arr);
	for (int i = 0; i < arr.size(); i++) {
		arr.get(i) = i + 100;
	}
	printMyArray(arr);

	arr.set(2, 0);
	printMyArray(arr);
	arr.popFront();
	printMyArray(arr);
	arr.popBack();
	printMyArray(arr);
	arr.insert(2, 3099);
	printMyArray(arr);

	// 检查浅拷贝
	//MyArray arr2 = arr;
	//printMyArray(arr2);
	//for (int i = 0; i < arr2.size(); i++) {
	//	arr2.get(i) = i + 10;
	//}
	//printMyArray(arr2);
	//printMyArray(arr);

}
void demo02() {
	MyArray arr(20);
	for (int i = 0; i < 20; i++) {
		arr[i] = i + 100;
	}
	cout << "arr.size()=" << arr.size() << endl;
	printMyArray(arr);
	MyArray arr2;
	arr2 = arr;
	printMyArray(arr2);
}

int main()
{
	//demo01();
	demo02();
	return 0;
}
