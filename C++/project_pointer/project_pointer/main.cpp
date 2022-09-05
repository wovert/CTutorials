#include <iostream>
using namespace std;

class Person {
public:
	int m_id;
	int m_age;
	int m_height;
	void display() {
		cout << "Person.m_id=" << this->m_id << endl;
		cout << "Person.m_age=" << this->m_age << endl;
		cout << "Person.m_height=" << this->m_height << endl;
	}
};

struct Animal {
	int m_id;
	int m_age;
	int m_height;
	void display() {
		cout << "animal.m_id=" << m_id << endl;
		cout << "animal.m_age=" << m_age << endl;
		cout << "animal.m_height=" << m_height << endl;
	}
};

void test02(void) {
	Person person;
	person.m_id = 10;
	person.m_age = 20;
	person.m_height = 30;
	// person对象的地址产地给 display 函数的 this
	person.display();

	Person *p = (Person *)&person.m_age;
	p->m_id = 40;
	p->m_age = 50;

	// 指针p存储的地址值传递给 display 函数的 this
	p->display();
}

void test01(void) {
	Animal animal;
	animal.m_id = 10;
	animal.m_age = 20;
	animal.m_height = 30;
	// person对象的地址产地给 display 函数的 this
	animal.display();

	Animal *a = (Animal *)&animal.m_age;
	a->m_id = 40;
	a->m_age = 50;

	// 指针p存储的地址值传递给 display 函数的 this
	a->display();
}

int main() {
	test01();
	// test02();

	getchar();
	return 0;
}