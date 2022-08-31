#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction(int num, int den=1) {
        this->m_numerator = num;
        this->m_denominator = den;
    }

    operator double() const {
        return (double) (m_numerator / m_denominator);
    }
private:
    int m_numerator; // 分子
    int m_denominator; // 分母
};

void test01() {
    Fraction f(3,5);
    double d = 4 + f;
    cout << d << endl;
}

int main() {
    test01();
    return 0;
}