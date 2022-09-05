#include <iostream>
using namespace std;

void display() {
	cout << "display() " << endl;
}

void display(int i) {
	cout << "display(int) " << i << endl;
}

void display(long i) {
	cout << "display(long) " << i << endl;
}

void display(double i) {
	cout << "display(double) " << i << endl;
}

void test(int a) {
	cout << "test(int) " << a << endl;
}

// Ä¬ÈÏ²ÎÊý
void func(int v1=2039, void(*p)(int)=test) {
	p(v1);
}

int sum(int v1, int v2=2) {
	return v1 + v2;
}