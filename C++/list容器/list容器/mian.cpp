#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>


using namespace std;

void printList(list<int> &L)
{
    for(list<int>::iterator it = L.begin() ; it != L.end() ; it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 双向链表
void test01() {
	list<int> mylist;
	
	for (int i = 0; i < 10; i++) {
		mylist.push_back(i);
	}

	list<int>::_Nodeptr node = mylist._Myhead()->_Next; // 头节点的下一个节点

	for (int i = 0; i < mylist._Mysize() * 2; i++) {
		cout << "Node:" << node->_Myval << endl; // 获取节点数据
		node = node->_Next; // 下一个节点
		if (node == mylist._Myhead()) { // 当前节点是否为头节点
			node = node->_Next; // 跳过头节点
		}
	}


}

bool myCompare(int v1, int v2) {
	return v1 > v2; // 降序第一个大于第二个数就可以
}

bool myFunc(int val) {
	return val > 20;
}

// 双向链表
void test02() {
	list<int> mylist;

	mylist.push_back(20);
	mylist.push_back(10);
	mylist.push_back(23);
	mylist.push_back(30);
	mylist.push_back(7);


	printList(mylist);
	mylist.reverse();  //反转链表
	printList(mylist);
	mylist.sort(myCompare);
	printList(mylist);
	mylist.remove_if(myFunc); // 删除大于20
	printList(mylist);

}

int main() {
	test02();
	//test01();
	return 0;
}