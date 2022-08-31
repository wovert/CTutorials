#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};



void test01() {
    Date d = {2022, 8, 3};

    // struct reference
    Date &ref = d;
    ref.day = 31;

    cout << ref.year << endl;
    cout << ref.month<< endl;
    cout << ref.day << endl;
}

void test02() {
    int age = 10;
    int *p = &age;

    // pointer reference
    int *&ref = p;

    *ref = 30;
    cout << age << endl; // 30
    cout << *p << endl; // 30
    cout << *ref << endl; // 30
}

void test03() {
    int array[] = {1,2,3};
    // array reference
    int (&ref)[3] = array;

    ref[0] = 10;
    cout << array[0] << endl; // 10

    // pointer array: in array has three char *
    char *arr[3] = {"hello", "world", "hi"};

    cout << arr[1] << endl; // world

    // array's pointer: int[3] + *arr2 = (&arr2)[3]
    int(*arr2)[3] = &array;

    (*arr2)[1] = 100;
    cout << "array[0]=" << array[0] << endl; // 10
    cout << "array[1]=" << array[1] << endl; // 100
    cout << "array[2]=" << array[2] << endl; // 3
}

int main() {
    // test01();
    // test02();
    test03();

    return 0;
}