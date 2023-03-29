#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct myfunc {
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void print(set<int> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
}

void print2(set<int, myfunc> &s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
}



void test01() {
	// 构造函数
	set<int> s;
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(8);
	s.insert(1);

	print(s); // 自身规则排序，从小到大
}

void test02() {
	// 构造函数
	set<int, myfunc> s;
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(8);
	s.insert(1);

	print2(s); // 自身规则派苏，从小到大
}

void test03() {
	// 构造函数
	set<int, myfunc> s;
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(8);
	s.insert(1);

	print2(s); // 自身规则派苏，从小到大
	s.insert(6);
	s.insert(5);
	s.insert(5); // 不允许有相同的元素,不把数据输入容器
	print2(s);

	pair<set<int, myfunc>::iterator, bool> ret = s.insert(3);

	if (ret.second) {
		cout << "success" << endl;
	}
	else {
		cout << "fail" << endl;
	}
	//s.erase(2);
	s.erase(s.begin());
	print2(s);
}

void p(int val) {
	cout << val << endl;
}
// 通过算法排序
void test04() {
	// 构造函数
	multiset<int> s;
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(8);
	s.insert(2);
	s.insert(1);

	// 不能通过算法排序来关联容器的元素
	//sort(s.begin, s.end());

	for_each(s.begin(), s.end(), p);
	cout << endl;


}


void test05() {
	// 构造函数
	multiset<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(8);
	s.insert(7);
	s.insert(6);

	
	set<int>::iterator it = s.find(3);
	if (it == s.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << "find success" << endl;
	}

	cout << s.count(2) << endl;

	// 查找大于等于2的最小的数
	it = s.lower_bound(2);
	if (it == s.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << "find success:" << *it << endl;
	}

	// 查找大于2的最小的数
	it = s.upper_bound(2);
	if (it == s.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << "find success:" << *it << endl;
	}

	// 大于等于2的两个最小的书，如果有2那么返回2和大于2的最小数
	pair < set<int>::iterator, set<int>::iterator> ret = s.equal_range(2);
	cout << *(ret.first) << endl;
	cout << *(ret.second) << endl;
}

class Maker {
public:
	Maker(string name, int age) {
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;

};

struct MakerFunc {
	bool operator()(const Maker &m1, const Maker &m2) {
		return m1.age < m2.age;
	}
};

void test06() {
	// 存储对象告诉set容器规则
	set<Maker, MakerFunc> s;
	s.insert(Maker("aaa", 1));
	s.insert(Maker("bbb", 2));
	s.insert(Maker("ccc", 3));
	s.insert(Maker("ddd", 4));
	s.insert(Maker("eee", 5));

	for (set<Maker, MakerFunc>::iterator it = s.begin(); it!= s.end(); ++it) {
		cout << "name=" << it->name << " age=" << it->age << endl;
	}
}

int main() {
	test06();
	//test05();
	//test04();
	//test03();
	//test02();
	//test01();
	return 0;
}