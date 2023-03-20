#include <iostream>
#include <string>

using namespace std;


void test() {
	int a;
	char c;
	cout << "输入字母:" << endl;  //输入ab4试试 
	cin >> a;    //由于输入的是字母，会出错
	cout << "cin.fail() = " << cin.fail() << endl; //因为输入出错，会输出1. 
	cout << "a = " << a << endl;  //没有输入成功，因此a是随机值 
	cin.sync();    //在流中fail()状态值无效的情况下，执行cin.sync(); 清空流是无效的 
	cout << "cin.fail() = " << cin.fail() << endl; //流中fail标志位仍然是1. 
	cin >> a;        //还是会读取'a'，仍然出错 
	cout << "cin.fail() = " << cin.fail() << endl; //因为输入出错，会输出1. 
	cout << "a = " << a << endl;  //输出和上面相同的随机值。 
	cin.sync();    //在流中fail()状态值为1的情况下，执行cin.sync(); 清空流是无效的

	cin.clear();   //将流中的所有状态值都重设为有效值 
	cin >> c;        //由于上面清空流无效，‘ab4’还在输入流中，这是读取'a' 
	cout << "c = " << c << endl;
	cin >> c;       //读取'b' 
	cout << "c = " << c << endl;
	cin >> a;       //读取'4' 
	cout << "a = " << a << endl;
	cout << "cin.fail() = " << cin.fail() << endl; //输入成功，错误标志位为0 

	cin.sync();  //这时流中fail()状态值为0，输入流被成功清空 
	cout << "输入数字\n";
	cin >> a;
	cout << "a = " << a << endl;
}

void demo() {
	cout.precision(4); // 有效长度
	cout.flags(cout.fixed);


	cout << 2.303959203 << endl; // 2.3040
	cout.unsetf(cout.fixed); // unset flag 充值有效长度
	cout << 2.303959203 << endl; // 2.303

}

int main() {
	//test();
	demo();
	return 0;
}