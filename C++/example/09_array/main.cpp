#include <iostream>
#include <array>
#include <vector>


void demoArray01() {
	int stuId[10]{}; // 初始化0

	// 数组所占用的空间大小
	std::cout << sizeof(stuId) << (char)10;
	for (int i = 0; i < 10; i++) {
		//std::cin >> stuId[i];
	}
	for (int i = 0; i < 10; i++) {
		std::cout << stuId[i] << (char)10;
	}
	// 数组个数
	std::cout << sizeof(stuId)/sizeof(stuId[0]) << (char)10;
}
void demoArray02() {
	int stuId[10]{}; // 初始化0
	int indexId{};
	int size = sizeof(stuId) / sizeof(stuId[0]);
	while (indexId < size) {
		std::cout << "请输入学号（输入0查看已登记的学生信息）：";
		std::cin >> stuId[indexId];

		bool repeatId{};
		for (int i = 0; i < indexId; i++) {
			if (stuId[indexId] == 0) {
				std::cout << i + 1 << "号 学生学号:" << stuId[i] << (char)10;
			} else if (stuId[indexId] == stuId[i]) {
				repeatId = true;
			}
		}
		if (stuId[indexId] != 0 && !repeatId) indexId++;
	}
}
void arrayLoop() {
	int a[]{ 65, 66, 67, 68, 69 };
	for (char k:a) {
		std::cout << k << (char)10;
	}
	for (auto k : a) {
		std::cout << k << (char)10;
	}
}
void demoStdArray() {
	// 原生数组
	int studentId[2]{ 10001,10002 };
	int studentId2[2]{ 9999,9999 };
	int studentId3[2]{ 9999,9999 };

	for (int x : studentId) {
		std::cout << x << std::endl;
	}
	std::cout << sizeof(studentId)/sizeof(studentId[0]) << (char)10;
	for (int x : studentId2) {
		std::cout << x << std::endl;
	}

	std::cout << studentId[100] << (char)10; 	// 可以访问
	std::cout << "比较=" << (studentId2 == studentId3) << (char)10; // false



	// std::array 原生数组存在着安全问题，使用不当会造成程序的泄漏
	std::array<int, 2> stuId{ 1001, 1002 };
	std::array<int, 2> stuId2{ 999, 999 };

	for (int x : stuId) {
		std::cout << x << std::endl;
	}
	std::cout << stuId.size() << (char)10;

	stuId.fill(999); // 每个元素指定的值
	for (int x : stuId) {
		std::cout << x << std::endl;
	}
	std::cout << stuId.at(1) << (char)10;
	//int a = stuId.at(100); // 抛出异常

	std::cout << "比较=" << (stuId == stuId2) << (char)10; // true

}
void demoVector() {
	std::vector<int> studentId1(5);
	std::vector<int> studentId2{ 100,200,300 };
	std::vector<int> studentId3(5, 100);
	
	for (int x:studentId1) {
		std::cout << x << (char)10;
	}
	for (int x : studentId2) {
		std::cout << x << (char)10;
	}
	for (int x : studentId3) {
		std::cout << x << (char)10;
	}

	// push
	studentId1.push_back(123);
	for (int x : studentId1) {
		std::cout << x << (char)10;
	}
	// init
	studentId1.assign(10, 100);
	for (int x : studentId1) {
		std::cout << x << (char)10;
	}
	// clear
	studentId1.clear();
	std::cout << studentId1.size() << (char)10;
	if (studentId1.empty()) {
		std::cout << "studentId1 is empty" << (char)10;
	}
}

int main()
{
	//demoArray01();
	//demoArray02();
	//arrayLoop();
	//demoStdArray();
	demoVector();
}
