#include <iostream>
using namespace std;

void add(int a, int b) {
	int result = a + b;
	cout << "add(int, int)" << result << endl;
}


void add(long a, long b) {
	int result = a + b;
	cout << "add(long, long)=" << result << endl;
}

void add(double a, double b) {
	int result = a + b;
	cout << "add(double, double)=" << result << endl;
}

int main()
{
	int a = 10;
	int b = 20;
	add(a, b);
	add(200L, 2020L);
	add(200.20, 2020.30);

    std::cout << "Hello!\n";
	return 0;
}