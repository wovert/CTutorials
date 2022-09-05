#include <iostream>
using namespace std;

// 被虚继承的基类叫做，虚基类
class Animal {
    public:
        int num;
        Animal(){
            this->num = 100;
        }
        // 动态编译，运行时绑定函数
        virtual void speak() {
            cout << "Animal speak" << endl;
        }

        // 静态编译，编译时绑定函数
        void run() {
            cout << "Animal speak" << endl;
        }
};

class Sheep :virtual public Animal {
public:
    void speak() {
        cout << "Sheep speak" << endl;
    }
};

class Camel :virtual public Animal {
public:
    void speak() {
        cout << "Camel speak" << endl;
    }
};

void doRun(Animal *animal) {
    animal->speak();
    animal->run();
}

void test1() {
    Sheep *sheep = new Sheep();
    doRun(sheep);

    Camel *camel = new Camel();
    doRun(camel);
}
int main() {
    test1();
    return 0;
}
