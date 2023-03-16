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
		cout << "Cat>>> name=" << this->pName << "(" << &this->pName << ") age=" << this->age << endl;
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

	// 左移运算符
	//operator<<() {

	//}
	void print() {
		cout << "Maker print():>>> id=" << this->id << ", age=" << this->age << endl;
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

class SmartPoint {
public:
	SmartPoint(Maker *m) {
		this->pMaker = m;
	}
	~SmartPoint() {
		if (this->pMaker != NULL) {
			cout << "析构函数" << endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
	//重载指针运算符
	Maker *operator->() {
		return this->pMaker;
	}
	// 重载星花
	Maker & operator*() {
		return *pMaker;
	}
private:
	Maker *pMaker;
};

void demo01() {
	Maker *m = new Maker;
	SmartPoint sm(m); // 栈区，调用析构函数
	sm->print();
	(*sm).print();
}


int main()
{
	demo01();
	return 0;
}
