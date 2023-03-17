#include <iostream>

using namespace std;

class Animal {
public:
	// virtual speak 动态编译,  没有则静态编译
	virtual void speak() {
		cout << "-------Animal------ speak" << endl;
	}
};

class Dog:public Animal {
public:
	void speak() {
		cout << "-------Dog------ speak" << endl;
	}
};

class Cat:public Animal {
public:
	void speak() {
		cout << "-------Cat------ speak" << endl;
	}
};

void doLogin(Animal *animal) {
	animal->speak();
}

void demo01() {
	Dog *d = new Dog;
	doLogin(d);

	Cat *c = new Cat;
	doLogin(c);
}
int main() {
	demo01();
	return 0;
}