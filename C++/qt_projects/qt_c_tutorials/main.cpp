#include <iostream>

//#include <string.h> // C ��ʱ���
#include <cstring> // C++����Cͷ�ļ���ʽ

using namespace std;

int main(int argc, char *argv[])
{
    char buf[128] = "";
    strcpy(buf, "���Ƶ�����");
    cout << buf << endl;
    return 0;
}
