#include <iostream>
using namespace std;


int main()
{
	int a = 10;

	// 8.25 -> 1000.01 -> 1.x*2^y(3指数，00001尾数)
	double d = reinterpret_cast<double&>(a);

	cout << "a = " << a << endl;
	cout << "d = " << d << endl;
	return 0;
}
