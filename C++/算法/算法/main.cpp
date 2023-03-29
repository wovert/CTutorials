#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

struct MyFunc {
	void operator()(int v1) {
		cout << v1 << " " << endl;
	}
};

// 第一步：继承 binary_function<参数1，参数2，返回类型>
struct MyFunc2:public binary_function<int, int, void> {
	void operator()(int v1, int v2) const { // 第二部加上const为常函数
		cout << "v1=" << v1 <<  endl;
		cout << "v2=" << v2 <<  endl;
		cout << v1+v2 <<  " " << endl; // 第三步 实现函数体
	}
};

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	//for_each(v.begin(), v.end(), MyFunc());

	// 第四步：用bind2nd来绑定函数对象
	// bind1st和bind2nd区别：参数位置不同
	for_each(v.begin(), v.end(), bind1st(MyFunc2(), 100));
	for_each(v.begin(), v.end(), bind2nd(MyFunc2(), 100));
	
	// 每个元素打印+100
}

struct MyNotFunc {
	bool operator()(int v) {
		return v >= 20;
	}
};
void test02() {
	// not1 和 not2
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);

	vector<int>::iterator it = find_if(v.begin(), v.end(), MyNotFunc());
	if (it == v.end()) {
		cout << "查找失败" << endl;
	}
	else {
		cout << "查找=" << *it << endl;
	}

	//not2
	//less 二元函数对象
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(50);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(20);
	//sort(v2.begin(), v2.end(), less<int>()); // 升序
	sort(v2.begin(), v2.end(), not2(less<int>())); // 降序
	
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " "; });
}

int main() {
	test02();
	//test01();
	return 0;
}