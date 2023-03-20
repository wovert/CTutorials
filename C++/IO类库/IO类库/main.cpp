#include <iostream>
#include <string>

using namespace std;


void test01() {
	// 如数的是as
	// 获取一个字符
	char c = cin.get();
	cout << c << endl; //a 

	c = cin.get();
	cout << c << endl; //s

	c = cin.get();
	cout << c << int(c) << endl;// 换行符

	c = cin.get(); // 阻塞
	cout << c << endl; //s

	char c1 = '0';
	cin.get(c1); // 一个参数，读取一个字符

	cout << c1 << endl;

	char ch1, ch2, ch3, ch4;
	cin.get(ch1).get(ch2).get(ch3).get(ch4);
	cout << ch1 << ch2 << ch3 << ch4;

}
void test02() {
	char buf[1024] = { 0 };

	// 两个参数 读取缓冲区时，换行不拿走
	cin.get(buf, 1024);
	char c = cin.get();
	if (c == '\n') {
		cout << "换行还在缓冲区" << endl;
	}
	cout << buf << "---end" << endl;
}

void test03() {
	char buf[1024] = { 0 };
	cin.getline(buf, 1024); // 读取缓冲区一行数据，换行符丢弃
	char c = cin.get(); // 阻塞
	if (c == '\n') {
		cout << "换行还在缓冲区" << endl;
	}
	cout << buf << "----" << endl;
}

void test04() {
	cin.ignore(); // 忽略第一个字符
	char c = cin.get();

	cout << c << "----" << endl;

	cin.ignore(3); // 忽略第一个字符
	c = cin.get();
	cout << c << "----" << endl;
}

void test05() {
	char c = cin.peek(); // 偷窥第一个字符
	cout << c << endl;

	char c2 = cin.get();
	cout << c2 << endl;
}

void test06() {
	char c = cin.get();
	//cin.putback(c); // 放回去
	cout << c << endl;

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}

void test07() {
	cout << "请输入一个字符串或数字" << endl;

	char c = cin.peek();

	if (c >= '0' && c <= '9') {
		int num;
		cin >> num;
		cout << "输入的数字时:" << num << endl;
	}
	else {
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "输入的字符串时:" << buf << endl;
	}
}

void test08() {
	int num;
	while (1) {
		cin >> num;
		if (num > 0 && num <= 10) {
			cout << "输入正确" << endl;
			break;
		}
		cout << "请重新属输入数字" << endl;
		// 重置标志位
		cin.clear();
		// 清空缓冲区
		cin.sync();
		// 2015
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);

		// 打印标志位
		cout << cin.fail() << endl;
	}
}
int main() {
	test08();
	//test07();
	//test06();
	//test05();
	//test04();
	//test03();
	//test02();
	//test01();
	return 0;
}