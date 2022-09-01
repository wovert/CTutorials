#include <iostream>

using namespace std;

// T 代表泛型的数据类型
template<class T> // 第一次编译
void mySwap(T &v1, T &v2) {
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template<class T>
void mySwap2() {
 
}

template<typename T>
T sum(T a, T b) {
    return a + b;
}

void test01() {
    int a = 10;
    int b = 20;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    // 编译器自动推导数据，以下是第二次编译
    mySwap(a, b);
    /**
        void mySwap(int &v1, int &v2) {
            int temp = v1;
            v1 = v2;
            v2 = temp;
        }
     */
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    // 数据类型要一致 
    // myswap(a, 'c');

    // <>参数列表告诉编译器只能传 int 类型
    mySwap<int>(a, b);

    // mySwap<double>(a, b); // 指定类型，传入时不能不一致

    // <>自动推导
    mySwap<int>(a, b);

    // mySwap2(); //  报错 没有指定泛型类型
    mySwap2<int>(); // 调用时，编译器必须知道 T 的数据类型

    // 使用参数列表指定数类型，则实参中隐士转换类型
    cout << sum<int>(10, 20.23) << endl;
}

int main() {
    test01();
    return 0;
}