#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	Student() {
		mid = 0;
	}
	Student(int id) {
		mid = id;
	}
	Student(const Student &s) {
		cout << "拷贝函数" << endl;
		this->mid = s.mid;
	}
	bool operator==(const Student &p) {
		if (this->mid == p.mid) {
			return true;
		}
		return false;
	}
	// 前置加加
	Student &operator++() {
		cout << "前置加加" << endl;
		++this->mid;
		return *this;
	}

	// 后置加加 占位参数必须是int
	Student operator++(int) {
		cout << "后置加加" << endl;

		// 先返回，后加加
		// *this的mid等与2
		Student temp(*this);
		++this->mid;
		return temp;
	}
	void print() {
		cout << "Student>>>> mid=" << this->mid << endl;
	}
public:
	int mid;
};

class Person {
	friend istream &operator>>(istream &in, Person &p);
private:
	string name;
	int age;
public:
	Person() {}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	int getAge() {
		return this->age;
	}
	void print() {
		cout << "Person>>> name=" << this->name << ", age=" << this->age << endl;
	}
};

class Cat {
private:
	char *pName;
	int age;
public:
	Cat() {}
	Cat(const char *name, int age) {
		cout << "sizeof(name)=" << sizeof(name) << endl;
		this->age = age;
		this->pName = new char[sizeof(name) + 1];
		strcpy_s(this->pName, sizeof(name) + 1, name);
	}
	Cat(const Cat &cat) {
		cout << "Cat>>> 拷贝函数" << endl;
		this->pName = new char[sizeof(cat.pName) + 1];
		this->age = cat.age;
	}
	~Cat() {
		if (this->pName != NULL) {
			delete[] this->pName;
			this->pName = NULL;
		}
	}
	Cat &operator=(const Cat &cat) {
		// 不能确定this指向的空间是否可以装下 cat中的数据
		// 所以先释放this->pName 指向的空间
		if (this->pName != NULL) {
			delete[] this->pName;
			this->pName = NULL;
		}
		// 申请堆区空间，大小由 cat 决定
		this->pName = new char[sizeof(cat.pName) + 1];
		// 拷贝数据
		strcpy_s(this->pName, sizeof(cat.pName) + 1, cat.pName);
		this->age = cat.age;

		// 返回对象本身
		return *this;
	}
	int getAge() {
		return this->age;
	}
	void print() {
		cout << "Cat>>> name=" << this->pName << "("  << &this->pName << ") age=" << this->age << endl;
	}
};


class Maker {
	// 访问类的私有成员，<< 重载函数声明为友元
	friend Maker operator+(Maker &m, Student &s);
	friend Student operator+(Student &s, Maker &m);
	friend ostream &operator<<(ostream &out, Maker &m);
public:
	Maker() {
		this->id = 0;
		this->age = 0;
	}
	Maker(int id, int age) {
		this->id = id;
		this->age = age;
	}
	Maker(const Maker &m) {
		cout << "拷贝构造" << endl;
		this->id = m.id;
		this->age = m.age;
	}
	// 双目运算符
	// 参数是加号的右边
	Maker &operator+(Maker &m) {
		cout << "双目运算符重载" << endl;
		//Maker temp(this->id + m.id, this->age + m.age);
		//return temp;
		this->id = this->id + m.id;
		this->age = this->age + m.age;
		return *this;
	}
	int operator-(Maker &m) {
		return this->age - m.age;
	}
	// 没有返回值，也没有 void
	operator bool() {
		if (this->id > 0) {
			return true;
		}
		return false;
	}
	bool operator!() {
		if (this->id <= 0) {
			return true;
		}
		return false;
	}
	operator int() {
		return 10;
	}

	// 左移运算符
	//operator<<() {

	//}
	void print() {
		cout << "Maker>>> id=" << this->id << ", age=" << this->age << endl;
	}
private:
	int id;
	int age;
};

// 全局方式运算符重载
// 编译器检查参数是否对应，第一个参数是加号的左边，第二个参数是加号的右边
//Maker operator+(Maker &m1, Maker &m2) {
//	Maker temp(m1.id + m2.id, m1.age + m2.age);
//	return temp;
//}

Maker operator+(Maker &m, Student &s) {
	Maker temp(m.id + s.mid, 20);
	return temp;
}

Student operator+(Student &s, Maker &m) {
	Student temp(m.id + s.mid);
	return temp;
}

// 1.形参和实参是一个对象
// 2.不能改变库类中的代码
// 3.ostream中把拷贝函数私有化了
ostream &operator<<(ostream &out, Maker &m) {
	cout << "全局左移运算符重载: id=" << m.id << ",age=" << m.age << endl;
	return out;
}

istream &operator>>(istream &in, Person &p) {
	in >> p.name;
	in >> p.age;
	return in;
}

ostream &operator<<(ostream &out, const Student &s) {
	cout << s.mid << endl;
	return out;
}

void demo01() {
	Maker m1(1, 10);
	Maker m2(2, 18);
	Maker m3(3, 20);

	// 编译器看到两个对象相加，那么编译器会执行operator+的函数
	// 拷贝构造
	Maker m4 = m1 + m2 + m3;
	m4.print();
	m1.print();
	m2.print();
	m3.print();
}

void demo02() {
	Maker m1(1, 20);
	Maker m2(2, 10);
	int result = m1 - m2;
	cout << "result=" << result << endl;
}

void demo03() {
	Maker m1(1, 20);
	cout << m1 << endl; // endl 是函数指针
	cout << 10; // ostream 内部重载了基础数据类型
}

void demo04() {
	Maker m1(1, 10);
	Student s1(10);
	Maker m2 = m1 + s1;
	m2.print();

	Student s2 = s1 + m1;
	s2.print();
}
void demo05() {
	Person p1("悟空", 30);
	Person p2("猪八戒", 10);
	cin >> p1 >> p2;
	p1.print();
	p2.print();
}
void demo06() {
	Person p1("张三", 10);
	Person p2;
	p2 = p1; // 赋值操作;默认赋值运算符重载函数进行简单的赋值操作
	p2.print();
}
void demo07() {
	Cat c1("丸子", 4);
	Cat c2("樱桃", 10);
	Cat c3("富贵", 14);
	//cat c1("wan", 4);
	//cat c2("ying", 10);

	c1.print();
	c2.print();
	c3.print();

	// 赋值操作
	c3 = c2 = c1; // c1赋值给c2, c2赋值给c3;
	cout << &(c2 = c3) << endl;
	cout << &(c2) << endl;



	c1.print();
	c2.print();
	c3.print();
}
void demo08() {
	Student s1(1);
	Student s2(1);
	if (s1 == s2) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}
void demo09() {
	Student s1(1);
	cout << s1 << endl; // 1
	cout << ++s1 << endl; // 2
	//s1++;
	cout << s1++ << endl; // 2 返回temp对象
	cout << s1 << endl; // 3
}
void demo10() {
	Maker m;
	if (m) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	Maker m2;
	if (!m2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	int b = (int)m;
	cout << "b=" << b << endl;
}
int main()
{
	//demo01();
	//demo02();
	//demo03();
	//demo04();
	//demo05();
	//demo06();
	//demo07();
	//demo08();
	//demo09();
	demo10();
	return 0;
}