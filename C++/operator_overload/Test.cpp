#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Maker {
    friend istream& operator>>(istream &in, Maker &m);
public:
    int id;
    int age;
    char *pName;
public:
    Maker() {
        this->id = 0;
        this->age = 0;
    }
    Maker(const char *name) {
        pName = new char[strlen(name)+1];
        strcpy(pName, name);
    }
    Maker(int id, int age) {
        this->id = id;
        this->age =age;
    }
    Maker(const Maker &m) {
        pName = new char[strlen(m.pName) + 1];
        strcpy(pName, m.pName);
    }
    ~Maker() {
        delete [] pName;
        pName = NULL;
    }
    // + m2
    Maker operator+(Maker &m2) {
        Maker temp(this->id+m2.id, this->age+m2.age);
        return temp;
    }

    Maker &operator=(const Maker &m) {
        // 不确定this->pName指向的空间是否能装下stu中的数据，先释放this->pName指向的空间
        if (this->pName != NULL) {
            delete[] this->pName;
            this->pName = NULL;
        }
        // 申请堆区空间，大小由m确定
        this->pName = new char[strlen(m.pName) + 1];
        strcpy(this->pName, m.pName);

        // 返回对象本身
        return *this;
    }

    // 前置++
    Maker &operator++() {
        ++this->id;
        return *this;
    }
    // 后置++, int占位参数，后加加
    Maker operator++(int) {
        Maker tmp(*this);
        ++this->id;
        return tmp;
    }

    void print() {
        cout << "name:" << pName << endl;
    }
};


// Maker operator+(Maker &m1, Maker &m2) {
//     Maker temp(m1.id+m2.id+1000, m1.age+m2.age+1000);
//     return temp;
// }


ostream& operator<<(ostream &out, Maker &m) {
    cout << m.id << endl;
}
istream& operator>>(istream &in, Maker &m) {
    in >> m.id;
    in >> m.age;
    return in;
}

void test01() {
    Maker m1(1, 20);
    Maker m2(2, 30);
    Maker m3 = m1 + m2;
    Maker m4 = m1 + m2 + m3;
    cout << "m4.id=" << m4.id << ", m4.age=" << m4.age << endl;
}

void test02() {
    Maker m1(1, 20);
    cout << m1 << endl;
}

void test03() {
    Maker m1(1, 20);
    Maker m2(2, 22);
    cin >> m1 >> m2;
    cout << "id=" << m1.id << ", age=" << m1.age << endl;
    cout << "id=" << m2.id << ", age=" << m2.age << endl;
}

void test04() {
    Maker m1(1, 20);
    Maker m2;
    m2 = m1;
    cout << "m2.id=" << m2.id << ", m2.age=" << m2.age << endl;
}

void test05() {
    Maker m1("张三");
    Maker m2("李四");
    Maker m3("王四");
    m1.print();
    m2.print();
    m2.print();

    // m3赋值给m2, m2赋值给m1
    m1 = m2 = m3; // 赋值操作

    cout << &(m2=m3) << endl;
    cout << &m2 << endl;

    // 如果返回的是值，m2=m3表达式返回一个新的对象
    // m1=m2=m3 赋值运算符本意是m3赋值给m2, m2赋值给m1
    // m2=m3表达式要返回m2这个对象，所以要返回引用

    m1.print();
    m2.print();
    m3.print();
}

void test06() {
    Maker m1(1, 20);
    ++m1;
    cout << m1.id << endl;
    m1++;
    cout << m1.id << endl;
}

int main() {
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    return 0;
}