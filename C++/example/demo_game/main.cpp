#include <conio.h>
#include <iostream>



void bankPw();
void gameLogin();

int main()
{
	gameLogin();
	bankPw();
}
void bankPw() {
	unsigned int passwd, repasswd;
linput:
	system("cls");
	std::cout << "请您输入一个6位数字密码：";
	std::cin >> passwd;
	std::cout << "请您再输入一个6位数字密码：";
	std::cin >> repasswd;

	if (passwd == repasswd) {
		if (passwd > 999999) goto linput;
		system("cls");
		std::cout << "密码设置成功!\n按下任意键进入破解系统";
		_getch(); // 等待输入任意键
		int testPass{};
	lhack:
		if (testPass != passwd) {
			testPass++;
			goto lhack;
		}
		else {
			std::cout << "密码破解成功" << testPass << (char)10;
		}
	}
	else goto linput;
}
