#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <string>


using namespace std;

class Maker {
public:
	Maker(string name, int age) {
		this->name = name;
		this->age = age;
	}
private:
	string name;
	int age;

public:
	void print() {
		cout << "name=" << this->name << " age=" << this->age << endl;
	}
};

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	while (!s.empty()) {
		// 输出栈顶
		cout << s.top() << " ";
		s.pop(); // 弹出栈顶元素
	}
	cout << "size:" << s.size() << endl;

	cout << "----------" << endl;

	stack<Maker> s1;
	s1.push(Maker("张三", 18));
	s1.push(Maker("李四", 28));
	s1.push(Maker("王五", 38));

	while (!s1.empty()) {
		// 输出栈顶
		s1.top().print();
		s1.pop(); // 弹出栈顶元素
	}
	cout << "size:" << s1.size() << endl;
}