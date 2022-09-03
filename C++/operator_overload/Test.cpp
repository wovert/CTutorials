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

class Person {
public:
    int pid;
public:
    Person(){}
    Person(int id) {
        this->pid = id;
    }
};

class Student {
public:
    int sid;
public:
    Student(){}
    Student(int id) {
        this->sid = id;
    }
};

// 全局方式
// Maker operator+(Maker &m1, Maker &m2) {
//     Maker temp(m1.id+m2.id+1000, m1.age+m2.age+1000);
//     return temp;
// }

void operator+(Person &p, Student &s) {
    int sum = p.pid + s.sid;
    cout << "sum=" << sum << endl;
}

void test01() {
    Maker m1(1, 20);
    Maker m2(2, 30);
    Maker m3 = m1 + m2;
    Maker m4 = m1 + m2 + m3;
    cout << "m4.id=" << m4.id << ", m4.age=" << m4.age << endl;
}

void test02() {
    Person p1(1);
    Student s1(2);
    p1 + s1;
}

int main() {
    // test01();
    test02();
    return 0;
}