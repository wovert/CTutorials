#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	bool res;
	//char path[] = "C:\\Users\\Administrator\\Desktop\\abc.txt";
	char path[] = "C:/Users/Administrator/Desktop/abc.txt";

	// delete file
	res = DeleteFileA(path);
	cout << "res=" << res << endl;
	// https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
	cout << "GetLastError=" << GetLastError() << endl;
	getchar();
	return 0;
}