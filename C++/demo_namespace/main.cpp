#include <iostream>

//using namespace std;

// �����ռ�ֻ�ܶ�����ȫ�ַ�Χ����
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

// ���������ռ�ı�ʶ��ֻ���ڱ��ļ��ڷ��ʣ��൱�ڸ������ʶ�������� static��ʹ���������Ϊ�ڲ�����
namespace {
  int a = 10;
  void func(){}
}

int main(int argc, char *argv[])
{
    std::cout << "data in A::name=" << A::name << A::data1 << std::endl;
    std::cout << "data in A::AA::data1=" << A::AA::data1 << std::endl;
    std::cout << "data in B::name=" << B::name << B::data1 << std::endl;


    //using A::AA::data1; // �� int data1 = 10000; ͬһ�����³�ͻ����
    using namespace A::AA; // ǿ�����������ռ���
    std::cout << "data1=" << data1 << std::endl; // �Ȳ鿴��ǰ��ͨ����data1, �ڲ鿴�����ռ���û��data1
    int data1 = 10000;
    std::cout << "data1=" << data1 << std::endl; // 10000 �������ԭ��
    return 0;
}
