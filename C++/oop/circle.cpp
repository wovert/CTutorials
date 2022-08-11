#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Circle {
    public:
        double mR;
    public:
        void setR(double r) {
            mR = r;
        }
        double getL() {
            return 2 * 31.4 * mR;
        }
};

void testCircle() {
    // 数据类型定义变量
    // 类实例化对象，有内存空间
    Circle c;
    c.setR(100);
    cout << "圆的的周长=" << c.getL() << endl;

}

int main() {

    testCircle();
    return 0;
}