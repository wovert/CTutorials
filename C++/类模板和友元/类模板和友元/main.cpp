#include <iostream>
#include <string>
#include "Maker.hpp"

using namespace std; 

void test01() {
	Maker<string, int> m("张三", 18);
	getMakerInfo(m);
}

int main() {
	test01();
	return 0;
}