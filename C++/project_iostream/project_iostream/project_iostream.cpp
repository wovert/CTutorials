#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void test01() {
	// 输入as
	char c = cin.get(); // a
	cout << c << int(c) << endl;
	c = cin.get(); // s
	cout << c << int(c) << endl;

	c = cin.get(); // 换行符
	cout << c << int(c) << endl;

	c = cin.get(); // v3：缓冲区没有内容 阻塞
	cout << c << ">>333<<" << int(c) << endl;

	char c1 = '0';
	cin.get(c1); // v3输入两个字符，第二个字符会覆盖c1上
	cout << "c1=" << c1 << int(c1) << endl;
	cout << "------------------" << endl;


}

void test02() {
	char ch1, ch2, ch3;
	cin.get(ch1).get(ch2).get(ch3);
	cout << ch1 << ch2 << ch3 << endl;
}

void test03() {
	char buf[1024] = { 0 };
	cin.get(buf, 1024); // 读取缓冲区时，换行符不拿走
	char c = cin.get(); // 读取换行符
	if (c == '\n') {
		cout << "换行还在缓冲区" << endl;
	}
	cout << buf << endl;
}

void test04() {
	char buf[1024] = { 0 };
	cin.getline(buf, 1024); //  读取缓冲区一行数据，换行符丢弃
	char c = cin.get(); // 阻塞
	if (c == '\n') {
		cout << "换行还在缓冲区" << endl;
	}
	cout << buf << endl;
}

void test05() {
	cin.ignore(); // 忽略前1个字符
	char c = cin.get();
	cout << c << endl;
}
void test06() {
	cin.ignore(3); // 忽略前三个字符
	char c = cin.get();
	cout << c << endl;
}

void test07() {
	char c = cin.peek(); // 偷窥第一个字符
	cout << c << endl;

	char c2 = cin.get();
	cout << c2 << endl;
}

void test08() {
	char c = cin.get();
	cout << c << endl;
	cin.putback(c); // 放回去

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}

void test09() {
	int num;
	cout << "----请输入数字----" << endl;
	while (1) {
		cin >> num;
		if (!cin.fail() && num >= 0 && num <= 10) {
			//cout << num << endl;
			cout << "输入正确" << endl;
			break;
		}
		cout << "重新输入数字:" << endl;
		cin.clear(); // 重置标志位
		//cin.sync(); // 清空缓冲区

		// 2015
		char buf[1024] = { 0 };
		cin.getline(buf, 1024); // 拿走所有缓冲区内容
	}
}


void test10() {
	cout.put('c');
	cout.put('a').put('b').put('c');

	char buf[] = "hello world";
	cout.write(buf, strlen(buf));
}

//  通过流成员函数实现格式化输出
void test11() {
	int num = 99;
	cout.width(20); // 设置宽度
	cout.fill('*'); // 填充*
	cout.setf(ios::left); // 左边对齐
	cout.unsetf(ios::dec); // 卸载十进制
	cout.setf(ios::hex); // 安装十六进制
	cout.setf(ios::showbase); // 显示基数 0x
	cout.setf(ios::oct); // 安装八进制

	cout << num << endl;
}


// 通过控制符格式化输出，引入头文件iomanip
void test12() {
	int num = 99;
	cout << setw(20); // 设置宽度
	cout << setfill('~');
	cout << setiosflags(ios::showbase);
	cout << setiosflags(ios::left);
	cout << hex;
	cout << oct;
	cout << dec;
	cout << num << endl;
}

void test13() {
	double d = 20.22;
	cout << setiosflags(ios::fixed); // 设置显示浮点数
	cout << setprecision(10); // 显示小数点后10位
	cout << d << endl;
}

void test14() {
	//  首先信息输出到缓冲区，然后写到文件
	// 定义流对象
	ofstream ofs;

	// 打开文件，写的方式，没有文件，则创建文件
	ofs.open("test.txt", ios::out | ios::trunc);

	// 判断是否打开成功
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
	}

	// 写信息
	ofs << "name: wovert" << endl;
	ofs << "age: 18" << endl;
	ofs << "height: 190" << endl;

	// close file
	ofs.close(); // 关闭文件，并刷新缓冲区

}
void test15() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
	}

	/// 1. 一行一行读取
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	// 2. 读文件
	//char buf[1024] = { 0 };

	//// 是否读到文件尾部
	//while (!ifs.eof()) {
	//	ifs.getline(buf, sizeof(buf));
	//	cout << buf << endl;
	//}

	// 3.单个字符读取
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}

	ifs.close();
}

class Maker {
public:
	char name[64];
	int age;
public:
	Maker() {}
	Maker(const char * name, int age) {
		this->age = age;
		strcpy(this->name, name);
	}
};

void test16() {
	// 二进制读写文件
	Maker m1("悟空", 18);
	Maker m2("贝吉塔", 22);

	ofstream ofs;
	ofs.open("text.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
	}

	ofs.write((const char *)&m1, sizeof(Maker));
	ofs.write((const char *)&m2, sizeof(Maker));

	ofs.close();
}
void test17() {
	ifstream ifs;
	ifs.open("text.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
	}
	// read
	Maker m1;
	Maker m2;
	ifs.read((char *)&m1, sizeof(Maker));
	ifs.read((char *)&m2, sizeof(Maker));

	cout << "name:" << m1.name << "，age:" << m1.age << endl;
	cout << "name:" << m2.name << "，age:" << m2.age << endl;

	ifs.close();
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	test17();
	system("pause");
	return 0;
}
