#include <iostream>
class Student {
public:
	// 无参构造函数
	Student() {
		std::cout << "无参构造函数" << std::endl;

	}

	// 防止编译器优化 Student s = 10; 这种格式
	// 只能放在只有一个参数或其他参数有默认值的构造函数
	explicit Student(const char *name) {
		std::cout << "构造函数" << std::endl;
		std::cout << "sizeof(name)" << sizeof(name) << std::endl;
		std::cout << "strlen(name)" << strlen(name) << std::endl;
		pName = (char *)malloc(sizeof(name));
		memset(pName, 0, sizeof(name));
		strcpy_s(pName, sizeof(name), name);
		age = 0;
	}
	Student(const char *name, int ageVal) {
		std::cout << "构造函数" << std::endl;
		std::cout << "sizeof(name)" << sizeof(name) << std::endl;
		std::cout << "strlen(name)" << strlen(name) << std::endl;
		pName = (char *)malloc(sizeof(name) + 1);
		memset(pName, 0, sizeof(name));
		strcpy_s(pName, sizeof(name) + 1, name);
		age = ageVal;
	}
	// 深拷贝：拷贝函数
	Student(const Student &std) {
		std::cout << "拷贝构造函数" << std::endl;
		pName = (char *)malloc(sizeof(std.pName));
		memset(pName, 0, sizeof(std.pName));
		strcpy_s(pName, sizeof(std.pName), std.pName);
		age = std.age;
	}
	~Student() {
		std::cout << "析构函数" << std::endl;

		if (pName != NULL) {
			free(pName);
			pName = NULL;
		}
	}
public:
	char *pName;
	int age;
};
int main()
{
	// C 语言方式在堆区申请空间 不会调用构造函数 对象释放时不会调用析构函数
	Student *stu = (Student *)malloc(sizeof(Student));
	memset(stu, 0, sizeof(Student));
	
	char name[] = "中文";
	
	std::cout << "sizeof(name)" << sizeof(name) << std::endl;

	stu->pName = (char *)malloc(sizeof(name) + 1);
	memset(stu->pName, 0, sizeof(name));
	std::cout << "sizeof(stu->pName)" << sizeof(stu->pName) << std::endl;


	strcpy_s(stu->pName, sizeof(name) + 1, name);

	stu->age = 18;
	std::cout << "stu Name" << (*stu).pName << " age=" << (*stu).age << std::endl;

	free(stu->pName);
	free(stu);

	// C++
	Student *stu2 = new Student(name, 18);
	delete stu2;
	stu2 = NULL;

	// array
	char *pChar = new char[64];
	memset(pChar, 0, 64);
	strcpy_s(pChar, sizeof(pChar), "张三");
	std::cout << pChar << std::endl;

	delete[] pChar;

	// Object Array

	// 调用无参构造函数
	Student *stuArr = new Student[2];
	memset(stuArr, 0, sizeof(Student)*2);
	for (int i = 0; i < 2; i++) {
		stuArr[i].pName = (char *)malloc(sizeof("张三"));
		memset(stuArr[i].pName, 0, sizeof("张三"));
		strcpy_s(stuArr[i].pName, sizeof("张三"), "张三");
	}
	delete[] stuArr;

	// 大部分编译器不支持 聚合初始化
	Student *stuArr2 = new Student[2]{Student("张三"), Student("李四")};
	delete[] stuArr2;

	void *m = new Student();
	delete m; 
	// void*接new的对象，不会调用析构函数 
	// 编译阶段，编译器可以确定函数的调用地址
	// C++ 编译器不识别 void *, 不知道 void指向的哪个 函数，所以不会调用析构函数
	


	return 0;
}