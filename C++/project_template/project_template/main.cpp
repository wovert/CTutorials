#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myarray.hpp"
#include "data.h"
#include "person.h"

int main()
{
	MyArray<int> arr;

	arr.pushBack(1);
	arr.pushBack(2);
	//cout << "capacity:" << arr.getCapacity() << endl;
	//cout << "size:" << arr.getSize() << endl;
	cout << arr;


	 MyArray<void *> arr2(20);
	 cout << "capacity:" << arr2.getCapacity() << endl;
	 cout << "size:" << arr2.getSize() << endl;
	 arr2.pushBack(new int(1));

	 Data *pData = new Data(01, 18);
	 Person *pPerson = new Person();

	 arr2.pushBack(pData);
	 arr2.pushBack(pPerson);

	 cout << "size:" << arr2.getSize() << endl;
	 ((Person *)arr2.getData(2))->print();
	 ((Data *)arr2.getData(1))->getInfo();

	 cout << arr2[2] << endl;

	 cout << arr2;

	getchar();
	return 0;
}