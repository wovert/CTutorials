#include <iostream>

using namespace std;

string name = "ȫ�ֱ���";
int globalName = 100;

int main(int argc, char *argv[])
{
    string name = "�ֲ�����";
    cout << "�ֲ����� name:" << name << endl;

    // ����������(::): ::a��ʾȫ�ֱ��� name
    cout << "ȫ�ֱ��� name:" << ::name << endl;
    cout << "ȫ�ֱ��� globalName:" << globalName << endl;
    return 0;
}
