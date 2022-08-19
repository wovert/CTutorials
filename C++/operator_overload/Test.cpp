#include <iostream>
using namespace std;

class Maker {
public:
    int id;
    int age;
public:
    Maker(int id, int age) {
        this->id = id;
        this->age =age;
    }
    // + m2
    Maker operator+(Maker &m2) {
        Maker temp(this->id+m2.id, this->age+m2.age);
        return temp;
    }
};

// 全局方式
// Maker operator+(Maker &m1, Maker &m2) {
//     Maker temp(m1.id+m2.id+1000, m1.age+m2.age+1000);
//     return temp;
// }

void test01() {
    Maker m1(1, 20);
    Maker m2(2, 30);
    Maker m3 = m1 + m2;
    Maker m4 = m1 + m2 + m3;
    cout << "m4.id=" << m4.id << ", m4.age=" << m4.age << endl;
}

int main() {
    test01();
    return 0;
}