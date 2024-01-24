
#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>


void prime(int, int);
void governmentProcurement();
void checkPrime();
void attackRouter();
void narcissisticNumber();
void perfectNumber();

// 求指数
void prime(int start = 3, int end = 1000) {
    bool flag{};
    short count{ 0 };
    int num{ 0 };

    // 指数不可能被2整除, 使用奇数
    //for (int i = start; i < end; i++) {
    for (int i = start; i < end; i += 2) {
        flag = false;
        //for (int c = 2; c < i; c++) {
        for (int c = 3; c <= sqrt(i); c += 2) {
            num++;
            if (i % c == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            count++;
            std::cout << std::setfill('0') << std::setw(3) << i << "\t";
            if (count % 10 == 0) std::cout << std::endl;
        }
    }
    std::cout << "\n累计计算量 : " << num << (char)10;
    std::cout << "\ntotal prime : " << count << (char)10;
}

// 政府采购项目
void governmentProcurement() {
    // 1万资金
    // 100件家具
    // 高级桌子每张500元
    // 普通桌子每张300元
    // 椅子三把100元
    int count{ 0 };
    /*
      ax500 + bx300 + cx(100/3) = 10000
      a + b + c = 100
      500 100 => 10000/500 => 20
      300 100 => 10000/300 => 33
    */
    int icount = 10000 / 500;
    int jcount = 10000 / 300;
    for (int i = 1; i <= icount; i++) {
        for (int j = 1; j <= jcount-i; j++) {
            int k = 100 - i - j;
            count++;
            if ((k%3 == 0) && (i * 500 + j * 300 + k * 100 / 3 == 10000)) {
                std::cout << "高级桌子数量: " << i << (char)10;
                std::cout << "普通桌子数量: " << j << (char)10;
                std::cout << "椅子数量: " << k << (char)10;
                std::cout << "-------------" << (char)10;
            }
        }
    }
    // 100 0000
    //  16 2925
    //   6 6000
    //   3 5320
    //      660
    //      392
    std::cout << "运算次数: " << count << (char)10;


    /*
    0 <= i <= 20
    0 <= j <= 33
    100-20-33 => 47 <= k <= 100
    
    ix500 + jx300 + kx(100/3) = 10000
    1500i + 900j + 100k = 30000
    15i + 9j + k = 300
    i + j + k = 100
     
    15i + 9j + 100 - i -j = 300
    14i + 8j + 100 = 300
    14i + 8j = 200
    7i + 4j = 100

    4j = 100-7i
    j = 25 - 7/4i;

    0 <= j <= 33

    0 <= 25 - 7/4i <= 33 
    i必须是4倍数
    i = 4num

    j = 25 - 7/4i
    j = 25-7num

    k=100-4num-25-7num
    k=75+3num

    num = ????????????

    0 <= 4num <= 20
    num <= 5

    0 <= 25-7num <= 33
    -25 <= -7num <= 7
    -25 <= -7num
    25/7 >= num
    3 >= num
    3 >= num <= 5

    0 <= 25-7num <= 33
    -25 <= -7num <= 7
    -25/7 <= -num
    25/7 >= num
    3 >= num
    
    45 <= 75+3num <= 100
    0 <= 30+3num <= 55-30
    -30 <= 3num <= 25
    num <= 25/3 = 7
    num <= 7
    
    */
    for (int num{0}; num <= 3; num++) {
        std::cout << "高级桌子数量: " << num*4 << (char)10;
        std::cout << "普通桌子数量: " << 25-num*7 << (char)10;
        std::cout << "椅子数量: " << 75+3*num << (char)10;
    }

}

void checkPrime() {
    int n{};
    char c{ 'Y' };
    
    do {
        std::cout << "\n请输入数字：";
        std::cin >> n;
        //std::cout << n << (char)10;

        int i = 1;
        bool flag{};
        flag = n % 2 != 0;

        //while (flag && i<=sqrt(n)) {
        //    if (i != 1 && n % i == 0) {
        //        flag = false;
        //        break;
        //    }
        //    i += n > 10 ? 2 : 1;
        //}
        do {
            if (i != 1 && n % i == 0) {
                flag = false;
                break;
            }
            i += n > 10 ? 2 : 1;
        } while (flag && i <= sqrt(n));


        if (flag) {
            std::cout << n << " 是质数." << (char)10;
        }
        else {
            std::cout << n << " 不是质数." << (char)10;
        }

        std::cout << "继续按下[Y]键 按下其他任意键退出程序";
        std::cin >> c;

    } while (c == 'Y' || c == 'y');

    std::cout << "退出程序\n";
}

// wps功能路由器入侵：模拟WPS路由器破解的场景
void attackRouter() {
    int passwd{ 87654321 };
    int crackPass{};
    // goto
//lcrack:
//    if (crackPass != passwd) {
//        crackPass++;
//        goto lcrack;
//    }
//    std::cout << "【goto版本】路由PIN=" << crackPass << (char)10;

    // for
    //for (crackPass = 0; crackPass == passwd; crackPass++);
    //std::cout << "【for版本】路由PIN=" << crackPass << (char)10;

    // while
    //crackPass = 0;
    //while (crackPass != passwd)crackPass++;
    //std::cout << "【while版本】路由PIN=" << crackPass << (char)10;

    // do while
    //crackPass = 0;
    //do crackPass++; while (crackPass != passwd);
    //std::cout << "【do while版本】路由PIN=" << crackPass << (char)10;
}

// 水仙花数：一个三位数立方和等于该数本身
// 153， 1立方，5立方，3立方 = 153 = 1+25*5+27= 125 + 28 = 153
void narcissisticNumber() {
    // 100-1000之间的水仙花数
    for (short i = 100; i < 1000; i++) {
        // 328
        short a = i/100; // 328/100 = 3
        short b = i/10%10;  //(328 - 300) / 10 = 2
        short c = i%10;
        if (a * a * a + b * b * b + c * c * c == i) {
            std::cout << i << "----> a^3=" << a*a*a << ",b^3=" << b*b*b << ", c^3=" << c*c*c << (char)10;
        }

    }
}

// 完数=出去自然是本身以外的一切因数和相等
void perfectNumber() {
    // 1000以内的完数 6=1 2 3
    for (int i = 1; i < 1000; i++) {
        int total{0};
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                total += j;
            }
        }
        if (total == i) {
            std::cout << total << (char)10;
        }
    }
}

int main()
{
    //prime();
    //governmentProcurement();
    //checkPrime();
    //attackRouter();
    //narcissisticNumber();
    perfectNumber();
}
