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
	strcpy(lisi.name, "��˹");

	char lisiInfo[128] = "";
	sprintf(lisiInfo, "��ţ�%d, ������%s, ���䣺%d", lisi.id, lisi.name, lisi.age);
	printf("%s\n", lisiInfo);
	
}

static void demo02() {
	// init
	struct Student s1 = { 2, "�����", 45 };
	char s1Info[128] = "";
	sprintf(s1Info, "��ţ�%d, ������%s, ���䣺%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);

	//  ��սṹ�����
	memset(&s1, 0, sizeof(s1));
	sprintf(s1Info, "��ţ�%d, ������%s, ���䣺%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);
}

// ��ȡ�����������ݴ���ṹ��
static void 	demo03() {
	struct Student s1;
	printf("�������� ���� ���䣺");
	scanf("%d %s %d", &s1.id, s1.name, &s1.age);
	char s1Info[128] = "";
	sprintf(s1Info, "��ţ�%d, ������%s, ���䣺%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);

	// 1��ʽ�������Ա��ֵ
	// 2��ʽ����ͬ���͵Ľṹ�����������ֱ�Ӹ�ֵ
	struct Student s2;
	char s2Info[128] = "";
	//s2 = s1;
	//strcpy(s2.name, "���»�");

	//sprintf(s2Info, "��ţ�%d, ������%s, ���䣺%d", s2.id, s2.name, s2.age);
	//printf("%s\n", s2Info);

	//sprintf(s1Info, "��ţ�%d, ������%s, ���䣺%d", s1.id, s1.name, s1.age);
	//printf("%s\n", s1Info);

	 // 3��ʽ���ײ�ʵ��
	memcpy(&s2, &s1, sizeof(struct Student));
	strcpy(s2.name, "����");
	s2.id = 2;
	s2.age = 30;
	sprintf(s2Info, "��ţ�%d, ������%s, ���䣺%d", s2.id, s2.name, s2.age);
	printf("%s\n", s2Info);

	sprintf(s1Info, "��ţ�%d, ������%s, ���䣺%d", s1.id, s1.name, s1.age);
	printf("%s\n", s1Info);
}

// �ṹ������
static void demo04() {
	struct Student arr[5] = {
		{1, "����", 29},
		{2, "����", 19},
		{3, "����", 20},
		{4, "����", 26},
		{5, "����", 35}
	};

	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("��ţ�%d, ������%s, ���䣺%d\n", arr[i].id, arr[i].name, arr[i].age);
	}
}
void testStruct() {
	//demo01();
	//demo02();
	//demo03();
	//demo04();
}