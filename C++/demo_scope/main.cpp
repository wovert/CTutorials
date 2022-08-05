#include <iostream>

using namespace std;

string name = "全局变量";
int globalName = 100;

int main(int argc, char *argv[])
{
    string name = "局部变量";
    cout << "局部变量 name:" << name << endl;

    // 作用域运算(::): ::a显示全局变量 name
    cout << "全局变量 name:" << ::name << endl;
    cout << "全局变量 globalName:" << globalName << endl;
    return 0;
}
