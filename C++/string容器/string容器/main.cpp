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


// 加入算法的回调函数
void MyPrint(int val) {
	cout << val << " ";
}

void print(string &s) {
	cout << "---->" << s << "=[" << "]<----" << endl;
}

// string 构造函数
void string01() {
	string s1;
	print(s1);
	string s2(10, 'a'); // 10个a
	print(s2);
	string s3(s2);
	print(s3);
	string s4("hello");
	print(s4);
}

// 基本赋值操作
/*
string &operator=(const char *s);
string &operator=(const string &s);
string &operator=(char c);
string &assign(const char *s)
string &assign(const char *s, int n)
string &assign(const string &s)
string &assign(int n, char c)
string &assign(const string &s,int start, int n)
*/
void string02() {
	string s1;
	s1 = "hello";
	print(s1);

	string s2;
	s2.assign(s1);
	print(s2);

	s2.assign("world");
	print(s2);
}
// 取得字符操作
void string03() {
	string s = "hello world";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s.at(i) << " ";
	}

	cout << endl;
}

/*
拼接操作
string &operator+=(const string& str)
string &operator+=(const char* str)
string &operator+=(const char c)
string &append(const char *s)
string &append(const char *s, int n)
string &append(const string &s)
string &append(const string &s, int pos, int n)
string &append(int n, char c)
*/
void string04() {
	string s1 = "aaa";
	s1 += "bbb";
	s1 += 'c';
	print(s1);

	s1.append("hello");
	print(s1);
	s1.append("abc", 2);
	print(s1);
}

/*
查找和替换
int find(const string &str, int post=0) const
int find(const char *s, int pos=0) const
int find(const char *s, int pos, int n) const
int find(const char c, int pos=0) const
int rfind(const string &str, int pos=npos) const
int rfind(const char *s, int pos = npos) const
int rfind(const char *s, int pos, int n) const
int rfind(const char c, int pos=0) const
string &replace(int pos, int n, const string &str)
string &replace(int pos, int n, const char *s)
*/
void string05() {
	string s = "abcdefgdabc";
	cout << s.find('d') << endl; // 3
	cout << s.rfind('d') << endl; // 7
	cout << s.find("KKK") << endl; // 4294967295

	s.replace(2, 4, "AAAA"); // abAAAAgdabc
	cout << s << endl;
}

/*
compare
 */
void string06() {
	string s1 = "hello";
	string s2 = "hello";

	const char *str = "world";

	if (s1.compare(s2)) {
		cout << "s1==s2" << endl;
	}

	if (s2.compare(str) == 0) {
		cout << "s2 == str" << endl;
	}
	else {
		cout << "s2 != str" << endl;
	}

}
/*
字串
*/
void string07() {
	string email = "wovert@google.com";
	int pos = email.find('@');

	string name = email.substr(0, pos);
	cout << name << endl;

	string domain = email.substr(++pos);
	cout << domain << endl;
}

void string08() {
	string s = "aaaa";
	s.insert(3, "AAA");
	cout << s << endl;

	s.insert(3, 5, 'M');
	cout << s << endl;

	s.erase(2, 3);
	cout << s << endl;

	s.clear();
	cout << s << endl;
}

void string09() {
	const char *str = "hello";
	string s = string(str);
	cout << s << endl;

	const char *str2 = s.c_str();
	cout << str2 << endl;
	printf("%p\n", str2);
}


// 字符串内存重新分配，[]和at 获取字符引用，可能会出错
void string10() {
	string s = "abcde";
	char &a = s[2];
	char &b = s[3];
	cout << s << endl;
	a = '1';
	b = '2';
	cout << s << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;

	cout << "字符串原空间地址:" << (int *)s.c_str() << endl;

	s = "asldkfjalksdjkfjaksldjflajsdklfjkl";
	cout << "字符串原空间地址:" << (int *)s.c_str() << endl;

	//a = '3'; // 原空间被释放，但是a还是被释放的a[2]空间的别名，操作非法的空间报错
}

// 迭代器遍历字符串
void string11() {
	string s = "hello";
	for (string::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	string11();
	//string10();
	//string09();
	//string08();
	//string07();
	//string06();
	//string05();
	//string04();
	//string03();
	//string02();
	//string01();
	return 0;
}