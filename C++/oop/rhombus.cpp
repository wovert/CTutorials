#include <iostream>
using namespace std;

// 被虚继承的基类叫做，虚基类
class Animal {
    public:
        int num;
        Animal(){
            this->num = 100;
        }
};

// 用虚继承方法基金二觉菱形继承中的二义性

// 两个父类中有祖类中的数据，子类会继承两个父类的数据，会产生二义性问题
/**
 *
 * 虚继承的原理
 * 1. 编译器给类添加一个指针，指针指向类似于表的组织，该表记录了该指针距离变量的偏移量
 * 2. 当子类多继承两个父类，那么只有一份成员变量，然后有两个指针；只有一份成员变量，不会产生二义性
 * 
 */

class Sheep :virtual public Animal {

};

class Camel :virtual public Animal {

};

class SheepCamel :public Sheep, public Camel {

};


void test1() {
    SheepCamel sc;
    cout << sc.num << endl; // 有二义性
}

void test2() {
    Sheep s;
    cout << s.num << endl; // 有二义性
    // 1. &s
    // 2. (int *)&s; 强制为int*类型
    // 3. *(int *)&s; 获取指针中的地址
    // 4. (int *)*(int *)&s; 指向表的首地址
    // 5. (int *)*(int *)&s + 1; 指向表存储偏移量的地址
    // 6. *((int *)*(int *)&s + 1); 偏移量
    cout << "偏移量=" << *((int *)*(int *)&s + 1) << endl;

    // 1. &s;
    // 2. (char *)&s; 跳转一个字节
    // 3. (char *)&s + *((int *)*(int *)&s + 1)
    // 4. 类型转换为 Animal 指针类型
    cout << ((Animal *)((char *)&s + *((int *)*(int *)&s + 1)))->num << endl;

}
int main() {
    // test1();
    test2();
    return 0;
}
