#include <iostream>
#include <string>

using namespace std;

class MyOut_of : public exception {
public:
	MyOut_of(const char *errorInfo) {
		// const char * 转换 string
		this->m_info = string(errorInfo);
	}
	MyOut_of(const string errorInfo) {
		this->m_info = errorInfo;
	}
	const char * what() const {
		// string 转黄为 const char*
		return this->m_info.c_str();
	}
public:
	string m_info;
};

class Maker {
public:
	Maker(int age) {
		if (age < 0 || age > 150) {
			//throw out_of_range("年龄不在范围内");
			throw MyOut_of("自己的异常类，年不在范围内");
		}
		else {
			this->age = age;
		}
	}
public:
	int age;
};

void test() {
	try {
		Maker m(200);
	}
	catch (MyOut_of &ex) {
		cout << ex.what() << endl;
	}
	catch (out_of_range &ex) {
		cout << ex.what() << endl;
	}
}

int main() {
	test();
	return 0;
}