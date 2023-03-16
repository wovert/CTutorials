#include <iostream>
class Student {
public:
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
		pName = (char *)malloc(sizeof(name));
		memset(pName, 0, sizeof(name));
		strcpy_s(pName, sizeof(name), name);
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
	Student s1("张三", 20);
	Student s2(s1);
	strcpy_s(s1.pName, sizeof(s1.pName), "李四");

	std::cout << "s1 Name" << s1.pName << " age=" << s1.age << std::endl;
	std::cout << "s2 Name" << s2.pName << " age=" << s2.age << std::endl;
	return 0;
}
