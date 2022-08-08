#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int id; // 4B
	char name[32]; // 32B
	int age; // 4B
};

static void demo01() {
	struct Student lucy;
	printf("%d\n", sizeof(lucy)); // 40
	printf("%d\n", sizeof(struct Student)); // 40

	struct Student lisi;
	lisi.id = 1;
	lisi.age = 10;
	strcpy(lisi.name, "李斯");

	char lisiInfo[128] = "";
	sprintf(lisiInfo, "编号：%d, 姓名：%s, 年龄：%d", lisi.id, lisi.name, lisi.age);
	printf("%s\n", lisiInfo);
	
}

static void demo02() {
	// init
	struct Student s1 = { 2, "齐达内", 45 };
	char s1Info[128] = "";
	sprintf(s1Info, "编号：%d, 姓名：%s, 年龄：%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);

	//  清空结构体变量
	memset(&s1, 0, sizeof(s1));
	sprintf(s1Info, "编号：%d, 姓名：%s, 年龄：%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);
}

// 获取键盘输入内容存入结构体
static void 	demo03() {
	struct Student s1;
	printf("请输入编号 姓名 年龄：");
	scanf("%d %s %d", &s1.id, s1.name, &s1.age);
	char s1Info[128] = "";
	sprintf(s1Info, "编号：%d, 姓名：%s, 年龄：%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);

	// 1方式：逐个成员赋值
	// 2方式：相同类型的结构体变量，可以直接赋值
	struct Student s2;
	char s2Info[128] = "";
	//s2 = s1;
	//strcpy(s2.name, "刘德华");

	//sprintf(s2Info, "编号：%d, 姓名：%s, 年龄：%d", s2.id, s2.name, s2.age);
	//printf("%s\n", s2Info);

	//sprintf(s1Info, "编号：%d, 姓名：%s, 年龄：%d", s1.id, s1.name, s1.age);
	//printf("%s\n", s1Info);

	 // 3方式：底层实现
	memcpy(&s2, &s1, sizeof(struct Student));
	strcpy(s2.name, "王五");
	s2.id = 2;
	s2.age = 30;
	sprintf(s2Info, "编号：%d, 姓名：%s, 年龄：%d", s2.id, s2.name, s2.age);
	printf("%s\n", s2Info);

	sprintf(s1Info, "编号：%d, 姓名：%s, 年龄：%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);
}

// 结构体数组
static void demo04() {
	struct Student arr[5] = {
		{1, "张三", 29},
		{2, "李四", 19},
		{3, "王五", 20},
		{4, "赵六", 26},
		{5, "刘七", 35}
	};

	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("编号：%d, 姓名：%s, 年龄：%d\n", arr[i].id, arr[i].name, arr[i].age);
	}
}
void testStruct() {
	//demo01();
	//demo02();
	//demo03();
	//demo04();
}