#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void test01() {
	pair<string, int> myp("aaa", 10);

	cout << myp.first << myp.second << endl;

	pair<int, string> myp2(1, "悟空");
	cout << myp2.first << myp2.second << endl;


}

int main() {
	test01();
	return 0;
}