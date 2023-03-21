#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

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

// 标准输出流
void test09() {
	cout.put('c');

	// 链式编程
	cout.put('a').put('a').put('\n');

	// 输出
	char buf[] = "hello world";
	cout.write(buf, strlen(buf));
	cout.put('\n');

	// 通过流函数实现格式化
	int num = 99;
	cout.width(20); // 设置宽度
	cout.fill('*'); // 填充
	cout.setf(ios::left); // 数据在左边
	cout.unsetf(ios::dec); // 卸载十进制
	cout.setf(ios::hex); // 设置16进制
	cout.setf(ios::showbase); // 显示基数
	cout.unsetf(ios::hex);
	cout.setf(ios::oct); // 显示8进制
	cout << num << endl;


}
void test10() {
	// 空过控制符格式化输出，引入头文件iomanp
	int no = 255;
	cout << setw(20); // 设置宽度
	cout << setfill('~');
	cout << setiosflags(ios::showbase);
	cout << setiosflags(ios::left);
	cout << hex;
	cout << oct;
	cout << dec;
	cout << no << endl;
}
void test11() {
	double d = 22.22;
	cout << setiosflags(ios::fixed); // 设置浮点数
	cout << setprecision(10); // 小数点后留多少位
	cout << d << endl;
}
void test12() {
	// 信息输出到缓冲区，然后写到文件
	ofstream ofs;
	

	// 打开文件，以写的方式，没有文件，则创建文件
	ofs.open("test.txt", ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
	}
	// 写文件
	ofs << "姓名：悟空" << endl;
	ofs << "age：20" << endl;
	ofs << "height：180cm" << endl;


	// 关闭文件
	ofs.close();
}
void test13() {
	// 从文件读取信息输出到缓冲区，然后写到屏幕
	ifstream ifs;

	// 打开文件，以写的方式，没有文件，则创建文件
	ifs.open("test.txt", ios::in);
	if (ifs.is_open() == false) {
		cout << "打开失败" << endl;
	}
	// 第一种方式读取文件
	// 一行一行读取
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	// 第二种方式读文件
	// 是否到文件末尾
	//char buf[1024] = { 0 };
	//while (!ifs.eof()) {
	//	ifs.getline(buf, sizeof(buf));
	//	cout << buf << endl;
	//}

	// 第三种方式读取文件
	// 单个字符
	char c;
	while ((c = ifs.get()) != EOF) {
		cout << c;
	}


	// 关闭文件
	ifs.close();
}


class Maker {
public:
	Maker() {}
	Maker(const char *name, int age) {
		this->age = age;
		strcpy_s(this->name, 64, name);
	}
public:
	// string类中有一个成员指针char *, 该指针指向了存储字符串的空间
	// string类中的数据存储到文件中，在读出来时，不能保证指针有效
	// string 开辟的空间如果大于16个字节就在堆区，小于就在栈区
	// string name;
	char name[64];
	int age;
};

void test14() {
	// 写二进制数据
	Maker m1("悟空", 29);
	Maker m2("贝吉塔", 32);

	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open()) {
		cout << "打开失败" << endl;
	}

	// write
	ofs.write((const char *)&m1, sizeof(Maker));
	ofs.write((const char *)&m2, sizeof(Maker));

	ofs.close();
	
}
void test15() {
	// 读二进制文件
	ifstream ifs;

	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开失败" << endl;
	}

	Maker m1;
	Maker m2;

	ifs.read((char *)&m1, sizeof(Maker));
	ifs.read((char *)&m2, sizeof(Maker));

	cout << "name:" << m1.name << " age:" << m1.age << endl;
	cout << "name:" << m2.name << " age:" << m2.age << endl;

	ifs.close();

}
int main() {
	test15();
	//test14();
	//test13();
	//test12();
	//test11();
	//test10();
	//test09();
	//test08();
	//test07();
	//test06();
	//test05();
	//test04();
	//test03();
	//test02();
	//test01();
	return 0;
}