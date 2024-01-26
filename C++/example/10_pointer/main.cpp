
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

	Person* p = (Person*)&person.m_age;
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

	Animal* a = (Animal*)&animal.m_age;
	a->m_id = 40;
	a->m_age = 50;

	// 指针p存储的地址值传递给 display 函数的 this
	a->display();
}

void demoPointer() {
	int* a{};
	int *b{};
	int* c{}, d{}; //int*, int
	int *e{}, *f{}; //int*, int*
	std::cout << a << ",size=" << sizeof(a) << (char)10;
	std::cout << b << (char)10;
	std::cout << c << (char)10;
	std::cout << d << (char)10;
	std::cout << e << (char)10;
	std::cout << f << (char)10;

	int num{ 100 };
	int* p_num{ &num };
	std::cout << p_num << (char)10;
	std::cout << *p_num << (char)10;
	*p_num = 200; // 修改内存地址值
	(*p_num)++;
	std::cout << p_num << (char)10;
	std::cout << *p_num << (char)10;
}

// 【指针数组】
// 1. 数组，
// 2:元素类型是某种数据类型的指针
void pointerArray() {
	int stuId[2][2]{ 
		{1001, 1002},
		{2001, 2002}
	};
	int* pStuId[2][2]; // 声明5个int类型的指针

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			pStuId[i][j] = &stuId[i][j];
			std::cout << "内存地址:" << pStuId[i][j] << "，值" << *pStuId[i][j] << (char)10;
		}
	}
	std::cout << pStuId << ",size=" << sizeof(pStuId) << (char)10;
	std::cout << *pStuId << ",size=" << sizeof(pStuId) << (char)10;
	std::cout << pStuId[0] << ",size=" << sizeof(pStuId) << (char)10;
	std::cout << pStuId[0][0] << ",size=" << sizeof(pStuId) << (char)10;
	//std::cout << "内存地址:" << pStuId[5] << "，值" << *pStuId[5] << (char)10;

}

// 指针转换
void pointerConvert() {
	unsigned ua { 999901 };
	int* p_ua = (int*)&ua;
	unsigned* ptr{ &ua };
	char* pch{};

	std::cout << *ptr << (char)10;
	std::cout << *p_ua << (char)10;
	std::cout << ua << (char)10;

	*p_ua = -1;
	pch = (char*)p_ua;
	*pch = 'A'; //65 => 41 FFFFFF41

	std::cout << *ptr << (char)10; // 按照 int 类型输出
	std::cout << *p_ua << (char)10; // 按照 int 类型输出
	std::cout << ua << (char)10; // 按照 unsinged 类型输出
	std::cout << sizeof(pch) << (char)10; // 4个字节
	std::cout << sizeof(pch) << (char)10; // 4个字节

	long long* pll_ua{ (long long*)&ua };

	// FF FF FF FF ua  &ua
	// 00 00 00 00 未知 (&ua)+4
	std::cout << std::hex << ua << (char)10; // 按照 int 类型输出
	std::cout << *p_ua << (char)10; // 按照 int 类型输出
	std::cout << *pll_ua << (char)10; // 按照 long long 类型输出
	std::cout << *((&ua) - 4) << (char)10; // long long 前4个字节的值
	std::cout << *((char*)pll_ua) << (char)10; // A

}

// 指针计算
void pointerCalc() {
	int a[]{ 10001,20001,30001 };
	int* pa{ &a[0] };
	for (int i=0; i<3; i++){
		std::cout << std::hex << &a[i] << (char)10;
	}
	std::cout << "-------" << (char)10;
	std::cout << std::dec <<  (*pa)++ << (char)10; // 10001
	std::cout << std::hex << pa << (char)10; // pa=&a[0]
	std::cout << std::dec << a[0] << (char)10; // 10002
	std::cout << "-------" << (char)10;

	std::cout << std::dec << *pa++ << (char)10; // 10002, 先*pa, 后pa++ => pa=&a[1]
	std::cout << std::hex << pa << (char)10; // pa=&a[1]
	std::cout << std::dec << a[0] << (char)10; // 10002
	std::cout << std::dec << a[1] << (char)10; // 20001

}

// 指针的指针
void pointerPointer() {
	int a[]{ 10001,20001,30001, 400001 };
	int* ptr{ &a[0] };
	int** pptr{ &ptr };
	
	std::cout << std::dec << "*ptr=" << * ptr << (char)10; // 10001
	std::cout << std::hex << "ptr=" << ptr << (char)10; // 0x004ffa20
	std::cout << std::hex << "pptr=" << pptr << (char)10; // 0x004ffa14
	std::cout << std::hex << "*pptr=" << *pptr << (char)10; // 0x004ffa20
	std::cout << std::dec << "**pptr=" << **pptr << (char)10; // 10001

	*pptr = &a[1];
	std::cout << std::dec << "*ptr=" << *ptr << (char)10; // 20001
	std::cout << std::hex << "ptr=" << ptr << (char)10; // 0x004ffa24
	std::cout << std::hex << "pptr=" << pptr << (char)10; // 0x004ffa18
	std::cout << std::hex << "*pptr=" << *pptr << (char)10; // 0x004ffa24
	std::cout << std::dec << "**pptr=" << **pptr << (char)10; // 20001

}

void constAndPointer() {
	// 常量指针：const 变量类型*，指针指向的是一个常量的内存地址，不能对其指向的内存地址进行改变，但是指针指向的地址可以改变
	// 常量指针的值得可以改变，但是不能修改常量指针指向的地址的值
	// 常量指针指向常量定义的变量
	const int a{ 1000 };
	const int b{ 1500 };
	int c{ 3500 };

	const int* pA{ &a };
	std::cout << *pA << (char)10;
	pA = &b;
	std::cout << *pA << (char)10;
	//*pA = 500; // error
	pA = &c;
	std::cout << *pA << (char)10;

	// 指针常量：变量类型* const，变量是一个常量，一旦初始化，就不可以再指向其他内存地址，但是内存地址里的值可以读写
	int x{ 100 };
	int y{ 150 };
	int* const pcA{ &x };
	std::cout << x << (char)10;
	std::cout << *pcA << (char)10;
	//pcA = &b; // error
	*pcA = 888;
	std::cout << x << (char)10;
	std::cout << *pcA << (char)10;


	// 指向常量的指针常量，这个指针变量是常量，一旦初始化不可以再指向其他内存地址，
	// 因为本身就是一个指向常量的指针，所以其指向的内存区域也不可以修改
	int const j{ 111 };
	int const k{ 555 };
	const int* const pcJ{ &j };
	std::cout << j << (char)10;
	std::cout << *pcJ << (char)10;
	//*pcJ = 888; // error
	//pcJ = &k; // error

	// 类型转换
	const int xx{ 0xa };
	const int yy{ 0xc };
	int* pXX{ (int*)&xx };

	std::cout << *pXX << (char)10; // 1111
	std::cout << xx << (char)10; // 1111
	std::cout << std::hex << "&xx=" << &xx << (char)10; // 1111
	std::cout << std::hex << "pXX=" << pXX << (char)10; // 1111
	*pXX = 0xb;
	std::cout << std::dec<< *pXX << (char)10; // 555 ？？？？？？？？？？？？？
	std::cout << std::dec <<  xx << (char)10; // 1111
	std::cout << std::hex << "&xx=" << &xx << (char)10; // 1111
	std::cout << std::hex << "pXX=" << pXX << (char)10; // 1111
}

int main()
{
	//test01();
	//test02();
	//demoPointer();
	//pointerArray();
	//pointerConvert();
	//pointerCalc();
	//pointerPointer();
	constAndPointer();

	system("pause");
	return 0;
}

