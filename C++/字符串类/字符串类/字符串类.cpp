// 字符串类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyString.h";

void demo01() {

	MyString s1(10, 'a');
	cout << s1 << endl;




	MyString s2(3, 'b');

	cout << s2 << endl;

	cout << "============" << endl;
	MyString s3 = s1 + s2;
	cout << "xxxxxxxxxx" << endl;
	cout << s3 << endl;

	MyString s4 = s3 + "hello";
	cout << s4 << endl;

	for (int i = 0; i < s4.size(); i++) {
		cout << s4[i] << " ";
	}
	cout << endl;

	MyString s5(5, 'c');
	s4 += s5;
	cout << s4 << endl;

	s4 += "world";
	cout << s4 << endl;

	cin >> s4;
	cout << s4 << endl;


}
int main()
{
	demo01();
	return 0;
}
