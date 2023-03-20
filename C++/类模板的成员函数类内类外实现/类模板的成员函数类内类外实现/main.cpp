#include <iostream>
#include <string>
#include "maker.hpp"

using namespace std;



void test01() {
	Maker<string, int> m("张三", 18);
	m.print();
}
int main() {
	test01();
	return 0;
}