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
    // �������Ͷ������
    // ��ʵ�����������ڴ�ռ�
    Circle c;
    c.setR(100);
    cout << "Բ�ĵ��ܳ�=" << c.getL() << endl;

}

int main() {

    testCircle();
    return 0;
}