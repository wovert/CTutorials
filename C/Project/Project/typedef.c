#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int INT32;

// ����ȡ����
typedef int ARR_TYPE[5];

// ָ��ȡ����
typedef int* P_TYPE;

// ����ָ��ȡ����
typedef int (*FUN_P)(int, int);

// �ṹ��ȡ����
//typedef struct person {
typedef struct {
	int id;
	char name[32];
	int age;
} Person, *Person_P;

int my_add(int v1, int v2) {
	return v1 + v2;
}

void testTypedef() {
	INT32 num = 10;
	printf("num=%d\n", num);

	ARR_TYPE arr = {10, 20 ,30, 40, 50};
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	int value = 10;
	P_TYPE p = &value;
	printf("p=%d\n", *p);

	FUN_P	pFun = my_add;
	int result = pFun(100, 200);

	printf("%d\n", result);

	Person person1 = { 1, "����", 20 };
	printf("��ţ�%d, ������%s, ���䣺%d\n", person1.id, person1.name, person1.age);

	Person_P pp = &person1; // *pp = *&person1 = person1

	printf("��ţ�%d, ������%s, ���䣺%d\n", (*pp).id, (*pp).name, (*pp).age);
	printf("��ţ�%d, ������%s, ���䣺%d\n", pp->id, pp->name, pp->age);

	// �Ӷ�������ṹ��ռ�
	Person *ren = NULL;
	ren = (Person *)calloc(1, sizeof(Person));
	if (NULL == ren) {
		perror("calloc error");
		return;
	}

	ren->id = 100;
	char tmp[32] = "���ɶ���";
	//strcpy_s(ren->name, strlen(tmp) + 1, tmp);
	strcpy(ren->name, tmp);
	ren->age = 23;
	printf("��ţ�%d, ������%s, ���䣺%d\n", ren->id, ren->name, ren->age);
	if (ren != NULL) {
		free(ren);
		ren = NULL;
	}
}