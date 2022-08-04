#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

static void testStrLen() {
	char buf[] = "hello world";
	char buf2[] = "hello world\0abc";
	char buf3[] = "hehe\123\\he";
	char bufSize[50] = "hello world";
	char *charP = "hello world";
	printf("%d\n", sizeof(charP)); // 4(32bit) or 8(64bit)
	printf("%d\n", sizeof(buf)); //12 ����\0
	printf("%d\n", strlen(buf)); // 11
	printf("%d\n", sizeof(bufSize)); //50
	printf("%d\n", strlen(bufSize)); // 11
	printf("%d\n", sizeof(buf2)); //16
	printf("%d\n", strlen(buf2)); // 11
	printf("%d\n", sizeof(buf3)); //9   \123Ϊ�˽���һ���ַ�83�� \\1���ַ�
	printf("%d\n", strlen(buf3)); // 8
}

char* my_strcpy(char *dest, const char *src) {
	//while (*src != '\0') {
	//	*dest = *src;
	//	dest++;
	//	src++;
	//}
	while (*dest++ = *src++);
	*dest = '\0';
	return dest;
}

static void testStrCpy() {
	char src[] = "Hello\0 World";
	char dest[128] = ""; 

	strcpy(dest, src);
	printf("dest=%s\n", dest);
	printf("sizeof(dest)=%d\n", sizeof(dest)); // 128
	printf("strlen(dest)=%d\n", strlen(dest)); // 11
	

	char dest2[128] = "";
	my_strcpy(dest2, src);
	printf("dest2=%s\n", dest2);


	char dest3[128] = "";
	strncpy(dest3, src, 20); // 20���ֽڣ� ���20����src���ȣ����ȡsrc���ַ�����
	printf("dest3=%s\n", dest3);
	printf("sizeof(dest3)=%d\n", sizeof(dest3)); // 128
	printf("strlen(dest3)=%d\n", strlen(dest3)); // 5
}

static void testStrCat() {
	char src[] = "Wor\0ld";
	char dest[256] = "hello";
	char dest2[256] = "word feather";
	
	printf("dest=%s\n", dest);
	printf("sizeof(dest)=%d\n", sizeof(dest)); // 256
	printf("strlen(dest)=%d\n", strlen(dest)); // 8
	strcat(dest, src);
	printf("dest=%s\n", dest);
	printf("sizeof(dest)=%d\n", sizeof(dest)); // 256
	printf("strlen(dest)=%d\n", strlen(dest)); // 8

	strncat(dest2, src, 2);
	printf("dest=%s\n", dest2);
	printf("sizeof(dest)=%d\n", sizeof(dest2)); // 256
	printf("strlen(dest)=%d\n", strlen(dest2)); // 14
}

static void testStrCmp() {
	char s1[] = "abcd";
	char s2[] = "abef";
	char s3[] = "abcdefg";
	if (strcmp(s1, s2) > 0) {
		printf("s1 > s2\n");
	} else if (strcmp(s1, s2) < 0) {
		printf("s1 < s2\n");
	} else if (strcmp(s1, s2) == 0)  {
		printf("s1 == s2\n");
	}

	if (strncmp(s1, s3, 4) > 0) {
		printf("s1 > s3\n");
	}
	else if (strncmp(s1, s3, 4) < 0) {
		printf("s1 < s3\n");
	}
	else if (strncmp(s1, s3, 4) == 0) {
		printf("s1 == s3\n");
	}
}

static void testStrChr() {
	char str[] = "hello world";
	char ch = 'w';
	char *search = NULL;
	if ((search = strchr(str, ch)) != NULL) {
		printf("��%s�в����ַ�%c\n", str, ch);
		printf("�ַ�����ʼλ��%u\n", (unsigned int)str);
		printf("�����ַ�λ��%u\n", (unsigned int)search);
		printf("����λ��λ��%d\n", search - str);
		printf("�����ַ�%c\n", *(str + (search - str)));
	}
	else {
		printf("��%s��û���ҵ��ַ�%c\n", str, ch);
	}
	while ((search = strchr(str, 'o')) && (*search = '#'));
	printf("%s\n", str);
}

static void testStrStr() {
	char str[] = "www.sex.777.sex.com www.sex.net";
	char searchStr[]= "sex";
	char *searchResult = NULL;
	searchResult = strstr(str, searchStr);
	if (searchResult != NULL) {
		printf("��%s�в����ַ�%s\n", str, searchStr);
		printf("�ַ�����ʼλ��%u\n", str);
		printf("�����ַ�λ��%u\n", (unsigned int)searchResult);
		printf("����λ��λ��%d\n", searchResult - str);
		printf("�����ַ�%c\n", *(str + (searchResult - str)));
	}
	else {
		printf("��%s��û���ҵ��ַ�%s\n", str, searchStr);
	}
	while ((searchResult = strstr(str, searchStr)) && memset(searchResult, '*', strlen(searchStr)));
	printf("%s\n", str);
}

void testStrFunc() {
	//testStrLen();
	//testStrCpy();
	//testStrCat();
	//testStrCmp();
	//testStrChr();
	testStrStr();
}