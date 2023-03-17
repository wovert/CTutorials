#include <iostream>

using namespace std;

class Animal {
public:
	// virtual speak 动态编译,  没有则静态编译
	virtual void speak() {
		cout << "-------Animal------ speak" << endl;
	}
	virtual void eat() {
		cout << "-------Animal------ eat" << endl;
	}
};

class Dog :public Animal {
public:
	virtual void speak() {
		cout << "-------Dog------ speak" << endl;
	}
};

class Cat :public Animal {
public:
	virtual void speak() {
		cout << "-------Cat------ speak" << endl;
	}
};

void doLogin(Animal *animal) {
	animal->speak();
}

void demo01() {
	Animal *d = NULL;

	d = new Dog;
	doLogin(d);
	delete d;

	d = new Cat;
	doLogin(d);
	delete d;
}
void demo02() {
	// 父类引用子类对象
	Animal * dog = new Dog();
	Animal * &d = dog;
	d->speak();
	delete dog;
}
int main() {
	//demo01();
	demo02();
	return 0;
}