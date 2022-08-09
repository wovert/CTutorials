#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static void readCharFile() {
	FILE *fp = NULL;
	char buf[128] = "";
	int i = 0;

	fp = fopen("a.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	// 调用一次读取一个字节
	buf[i] = fgetc(fp);
	while (buf[i] != EOF) {
		i++;
		buf[i] = fgetc(fp);
	}
	printf("buf=%s\n", buf);

	fclose(fp);
}

static void writeCharFile() {
	FILE *fp = NULL;
	char buf[128] = "";
	int i = 0;

	fp = fopen("a.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	printf("请输入要写入文件字符串：");
	fgets(buf, sizeof(buf), stdin); // 会获取换行符
	buf[strlen(buf) - 1] = 0;  // 去掉键盘输入的换行符

	while (buf[i] != '\0') {
		fputc(buf[i], fp);
		i++;
	}

	fclose(fp);
}

static void writeStringFile() {
	FILE *fp = NULL;
	char *buf[] = {"01\n", "02\n", "03\n"};
	int n = sizeof(buf) / sizeof(buf[0]);
	int i = 0;

	fp = fopen("a.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}

	for (i = 0; i < n; i++) {
		fputs(buf[i], fp);
	}

	fclose(fp);
}

static void readStringFile() {
	FILE *fp = NULL;
	char buf[128] = "";
	int i = 0;

	char *path = "a.txt";
	fp = fopen(path, "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}


	// 从文件中读取一行数据
	while (fgets(buf, sizeof(buf), fp) != NULL) {
		printf("%s\n", buf);
	}

	fclose(fp);
}

void testFile() {
	//readCharFile();
	//writeCharFile();
	//writeStringFile();
	readStringFile();
}