#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const int n = 1e8;

int sum1(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += pow(-1, i); // (-1)^i
	}
	return sum;
}

int sum2(int n) {
	int sum = 0;
	if (n % 2 == 0) {
		sum = 0;
	}
	else {
		sum = -1;
	}
	return sum;
}

void test01() {
	time_t startTime, endTime, durationTime;
	startTime = clock(); // 开始时间
	cout << "sum1:" << sum1(n) << endl;
	endTime = clock(); // 结束时间
	durationTime = endTime - startTime;
	cout << "time:" << durationTime << endl; // 毫秒
}

void test02() {
	time_t startTime, endTime, durationTime;
	startTime = clock(); // 开始时间
	cout << "sum2:" << sum2(n) << endl;
	endTime = clock(); // 结束时间
	durationTime = endTime - startTime;
	cout << "time:" << durationTime << endl; // 毫秒
}

int main() {
	test02();
	test01();
	return 0;
}
