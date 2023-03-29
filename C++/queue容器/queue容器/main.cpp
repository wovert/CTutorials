#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
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
	

	queue<Maker *> q;
	q.push(new Maker("张三", 18));
	q.push(new Maker("李四", 28));
	q.push(new Maker("王五", 38));

	while (!q.empty()) {
		q.front()->print();
		q.pop();
	}
	cout << "size:" << q.size() << endl;
}