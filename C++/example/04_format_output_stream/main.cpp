#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <bitset>

#include <conio.h>

int main()
{
    int test{ 5 };
    test *= 9;

    int test2{ 5 };
    test2 *= 2;

    int test3{ -100 };
    test3 >>= 1;
    std::cout << test3 << (char)10;

    std::cout << std::fixed; // 小数计数法
    std::cout << 3E20 << char(10);

    std::cout << std::scientific; // 科学计数法
    std::cout << 3.14 << (char)10;

    std::cout << std::defaultfloat; // 默认
    std::cout << 3.14 << (char)10;

    std::cout << std::setprecision(3); // 小数点留多少 iomanip包
    std::cout << 3.1415926 << std::endl;

    std::cout << std::hex;
    std::cout << 65535 << std::endl;
    std::cout << (long long)65535 * 65535 << std::endl;

    std::cout << std::showbase; // 显示进制表示
    std::cout << std::oct;
    std::cout << 9 << std::endl;

    std::cout << std::noshowbase;
    std::cout << 9 << std::endl;

    std::cout << std::dec;
    std::cout << std::setw(10) << 1 << std::endl; // setw长度 iomanip
    std::cout << std::setw(10) << 123 << std::endl; // iomanip
    std::cout << std::setfill('*') << std::setw(10) << 1234 << "*" << std::endl; // iomanip

    std::cout << std::left;
    std::cout << std::setfill('*') << std::setw(10) << 1234 << "*" << std::endl; // iomanip

    std::cout << std::right;
    std::cout << std::setfill('*') << std::setw(10) << 1234 << "*" << std::endl; // iomanip


    // output bin
    int x{ (int)0b11 };
    std::cout << "3=" << std::bitset<32>(x) << (char)10;
    std::cout << "-3=" << std::bitset<32>(-x) << (char)10;

    int a{ (int)0b111111111111100111111111111111111111 };
    std::cout << a << (char)10;
    std::cout << std::bitset<32>(a) << (char)10;

    a <<= 8; // 低位补0
    std::cout << "a <<=8 =>" << std::bitset<32>(a) << (char)10;

    unsigned b{ (unsigned)a };
    std::cout << "b=" << std::bitset<32>(b) << (char)10;
    b >>= 7; // 高位补0
    std::cout << "b>>=7" << std::bitset<32>(b) << (char)10;

    a >>= 7; // 高位补原来的最高位
    std::cout << std::bitset<32>(a) << (char)10;



    int num1 = 10;
    int num2 = 20;
    std::cout << "交换数据 a=" << num1 << ", b=" << num2 << (char)10;
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    std::cout << "交换后数据 a=" << num1 << ", b=" << num2 << (char)10;

    // printf: d, o, u, x/X, f, lf, s, 0, +
    printf("%+05d\n", 100);
    printf("%#05X\n", 255);
    printf("%.3lf\n", -3.1415926);
    printf("%u\n", -1);
    printf("%我的名字是%s\n", "张三");

    // scanf: d, o, u, x/X, f, lf, s
    int age { 0 };
    scanf("%d", &age);
    printf("age=%d\n", age);

    int a1, b1, c1;
    scanf_s("%x%d%d", &a1, &b1, &c1);
    printf("a1=%x, b1=%d, c1=%d\n", a1, b1, c1);

    // getch => <conio.h>
    int uin = _getch(); // 输入按键的值（ASCII码）
    printf("%d\n", uin); //a => 97

    system("pause");
}

