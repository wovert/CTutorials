#include <iostream>

using std::cout;
using std::cin;

int a{ 100 };

void game();
void test();

int main()
{
	int a{ 160 };
	{
		int c{ 260 };
		int a{ 350 };
		{
			char a = 'A';
			cout << a << char(10);
			cout << ::a << (char)10; // 使用限定符调用全局变量;

			cout << c << (char)10;
		}
		cout << a << (char)10;
	}

	//game();
	test();
}

void game() {
	typedef unsigned int usi;

	usi diamond { 6000 };
	usi vip_exp { 8000 };

	unsigned xbase = diamond ^ vip_exp;

	cout << "修改钻石量：";
	cin >> diamond;
	cout << "修改累计消费：";
	cin >> vip_exp;

	// 模拟一次检查
	usi realDiamond = xbase ^ vip_exp;
	usi realVip_exp = xbase ^ diamond;
	cout << "您应该的钻石量是：" << realDiamond << ", 您实际的钻石量是:" << diamond << (char)10;
	cout << "您应该的累计消费是：" << realVip_exp << ", 您实际的累计消费是:" << vip_exp << (char)10;
}

void test() {
	int a{ 0x283f };
	
	/*
		1+ a = 0x2840
		0x2840 << a = 0x2840 * 2 = 0x5f80

		0x 2840
		0x    2
		--------
		0x 5080

		0x5080 & 0x00FF = 0x0080
		0x0080 | 0xF = 0x008f

		350A x 12 = ?
		0x 350A
		0x   12
		---------
		   6A14        10x2=20, 20-16=4
		  350A 
		---------
		  3BAB4

		  10 => 0,1,2,3,4,5,6,7,8,9 => 0-9
		    9
		  + 5
		  -----
		  1 4

		 359  => 9x10^0 + 5x10^1 + 3x10^2 = 9 + 50 + 30
		+  4
		------
		  63

		  16 => 0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f => 0-f
		  0 d => 13
		  + 8
		  ----
		  2 5

		  f 4 => 4*16^0 + f*16^1= 4 + 15x16 = 4 + 150+90=245
		+   1
		-----
	*/
	int b = 1 + a << 1 & 0x00FF | 0xF;
	cout << std::hex;
	cout << 0x2840 * 2 << (char)10;
	cout << b << (char)10;
}