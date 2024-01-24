#include <iostream>
#include <cctype> // 字符处理函数

using namespace std;

int main()
{
	char a, c;
	bool b;
	cout << "请输入小写字符：";
	cin >> a;
	c = toupper(a);
	b = isupper(c);
	cout << c << (char)10;
	cout << std::boolalpha << b << (char)10;

	cout << "请输入大写字符：";
	cin >> a;
	c = tolower(a);
	b = islower(c);
	cout << c << (char)10;
	cout << std::boolalpha << b << (char)10;



}
