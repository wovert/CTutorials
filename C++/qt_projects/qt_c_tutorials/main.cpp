#include <iostream>

//#include <string.h> // C 旧时风格
#include <cstring> // C++调用C头文件方式

using namespace std;

int main(int argc, char *argv[])
{
    char buf[128] = "";
    strcpy(buf, "复制的内容");
    cout << buf << endl;
    return 0;
}
