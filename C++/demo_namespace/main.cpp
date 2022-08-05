#include <iostream>

//using namespace std;

// 命名空间只能定义在全局范围声明
namespace A {
    std::string name = "A";
    int data1 = 10;
    namespace AA {
        int data1 = 101;
    }
}

namespace B {
    std::string name = "B";
    int data1 = 20;
}

// 无名命名空间的标识符只能在本文件内访问，相当于给这个标识符加上了 static，使得其可以作为内部连接
namespace {
  int a = 10;
  void func(){}
}

int main(int argc, char *argv[])
{
    std::cout << "data in A::name=" << A::name << A::data1 << std::endl;
    std::cout << "data in A::AA::data1=" << A::AA::data1 << std::endl;
    std::cout << "data in B::name=" << B::name << B::data1 << std::endl;


    //using A::AA::data1; // 与 int data1 = 10000; 同一级别导致冲突报错
    using namespace A::AA; // 强调的是命名空间名
    std::cout << "data1=" << data1 << std::endl; // 先查看当前普通变量data1, 在查看命名空间有没有data1
    int data1 = 10000;
    std::cout << "data1=" << data1 << std::endl; // 10000 访问最近原则
    return 0;
}
