#include <iostream>
#include <vector> // 容器
#include <algorithm> // 算法
#include <string>

using namespace std;

template<class T>
class MyArray {
public:
	// 保护原生指针，给原生指针取别名
	typedef T* iterator;
	MyArray() {
		mCapacity = 10;
		mSize = 10;
		p = new T[mCapacity];
		for (int i = 0; i < mCapacity; i++) {
			p[i] = i + 1;
		}
	}
	// 提供迭代器
	T* begin() {
		return p;
	}
	// 结束位置的迭代器
	T* end() {
		return p + mSize;
	}
public:
	T* p;
	int mCapacity;
	int mSize;
};

// 算法设计
template<class T>
void print(T begin, T end) {
	for (; begin != end; ++begin) {
		cout << *begin << " ";
	}
	cout << endl;
}

class Maker {
public:
	string name;
	int age;
public:
	Maker() {

	}
	Maker(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

ostream &operator<<(ostream &out, Maker &m) {
	out << "name=" << m.name << " age=" << m.age << endl;
	return out;
}

void test01() {
	MyArray<int> arr;

	// 获取容器提供的开始位置的迭代器
	MyArray<int>::iterator begin = arr.begin();
	// 获取容器提供的结束位置迭代器
	MyArray<int>::iterator end = arr.end();

	print(begin, end);
}

// 加入算法的回调函数
void MyPrint(int val) {
	cout << val << " ";
}
void test02() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	// 获取开始位置的迭代器
	vector<int>::iterator begin = v.begin();
	// 获取结束位置的迭代器
	vector<int>::iterator end = v.end();

	// 遍历算法
	for_each(begin, end, MyPrint);
	cout << endl;

}
void test03() {
	vector<Maker> v;
	v.push_back(Maker("悟空1", 18));
	v.push_back(Maker("悟空2", 28));
	v.push_back(Maker("悟空3", 38));
	v.push_back(Maker("悟空4", 48));
	v.push_back(Maker("悟空5", 58));

	// 获取开始和结束位置的迭代器
	vector<Maker>::iterator begin = v.begin();
	vector<Maker>::iterator end = v.end();

	while (begin != end) {
		cout << (*begin);
		begin++;
	}
}
void test04() {
	// 存储对象的指针
	vector<Maker *> v;
	Maker *m1 = new Maker("悟空1", 18);
	Maker *m2 = new Maker("悟空2", 28);
	Maker *m3 = new Maker("悟空3", 38);
	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);

	// 获得开始指针
	vector<Maker *>::iterator begin = v.begin();
	vector<Maker *>::iterator end = v.end();

	while(begin != end) {
		cout << (*begin)->name << " " << (*begin)->age << endl;
		++begin;
	}
}
// 容器嵌套容器
void test05() {
	vector<vector<int>> vs;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for(int i=0; i<3; i++){
		v1.push_back(i + 10);
		v2.push_back(i + 10);
		v3.push_back(i + 10);
	}
	vs.push_back(v1);
	vs.push_back(v2);
	vs.push_back(v3);

	vector<vector<int>>::iterator begin = vs.begin();
	vector<vector<int>>::iterator end = vs.end();

	while (begin != end) {
		vector<int>::iterator sbegin = (*begin).begin();
		vector<int>::iterator send = (*begin).end();

		while (sbegin != send) {
			cout << *sbegin << " ";
			++sbegin;
		}
		++begin;
		cout << endl;
	}

}
void stringFunc01() {
	// string 构造函数
	string s1;
	string s2(10, 'a');
	string s3(s2);
	string s4("hello");

	// 赋值操作



}
int main() {
	stringFunc01();
	test05();
	//test04();
	//test03();
	//test02();
	//test01();
	return 0;
}