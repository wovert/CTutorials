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
        cout << "-----------------------" << endl;
    }
};

struct Animal {
    int m_id;
    int m_age;
    int m_height;
    void display() {
        // animal.display(); 刚好是this=person对象地址
        // mov eax, dword ptr [this]
        // eax == &person
        // [eax], [eax + 4], [eax + 8]
        // [&person], [&person + 4], [&person + 8]

        // a->display(); 是this=&person.m_age对象地址
        // mov eax, dword ptr [this]
        // eax == &person.m_age = &person + 4
        // [eax], [eax + 4], [eax + 8]
        // [&person + 4], [&person + 4 + 4], [&person + 4 + 8]
        cout << "animal.m_id=" << m_id << endl;
        cout << "animal.m_age=" << m_age << endl;
        cout << "animal.m_height=" << m_height << endl;
        cout << "-----------------------" << endl;
    }
};

void test02(void) {
    Person person;
    person.m_id = 10;
    person.m_age = 20;
    person.m_height = 30;
    person.display();

    Person *p = (Person *)&person.m_age;
    p->m_id = 40;
    p->m_age = 50;

    // person对象的地址产地给 display 函数的 this
    person.display();

    // 指针p存储的地址值传递给 display 函数的 this
    // 将&person.m_age传递给display 函数的this
    p->display();
}

void test01(void) {
    Animal animal;
    animal.m_id = 10;
    animal.m_age = 20;
    animal.m_height = 30;
    // animal.display();

    // eax == &person.m_age == &person + 4

    // mov eax, dword ptr [a]
    Animal *a = (Animal *)&animal.m_age;

    // mov dword ptr [eax + 0], 40
    // mov dword ptr [&person + 4 + 0], 40
    a->m_id = 40;

    // mov dword ptr [&person + 4 + 4], 50
    a->m_age = 50;

    // person对象的地址产地给 display 函数的 this
    animal.display();

    // 指针p存储的地址传递给 display 函数的 this
    // 将 &animal.m_age 传递给 display 函数的this
    // a->display();
}

int main() {
    test01();
    // test02();


    return 0;
}