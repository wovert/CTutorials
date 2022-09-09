#include <iostream>

int divide(int a, int b) {
	if (b == 0) {
		throw "不能为0";
	}
	return a / b;
}


void test01() {
	std::cout << 1 << std::endl;
	for (int i = 0; i < 9999999; i++) {
		try {
			int *p = new int[999999];
		}
		catch (...) {
			std::cout << "异常：内存不够" << std::endl;
			break;
		}
	}

	std::cout << 2 << std::endl;
}

void test02() {
	try {
		divide(20, 0);
	}
	catch (int exception) {
		std::cout << "异常:" << exception << std::endl;
	}
	catch (const char *exception) {
		std::cout << "异常:" << exception << std::endl;
	}
}
int main()
{
	//test01();
	test02();
	getchar();
	return 0;
}