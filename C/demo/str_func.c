#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void testStrLen() {
	char buf[] = "hello world";
	char buf2[] = "hello world\0abc";
	char buf3[] = "hehe\123\\he";
	char bufSize[50] = "hello world";
	char *charP = "hello world";
	printf("%d\n", sizeof(charP)); // 4(32bit) or 8(64bit)
	printf("%d\n", sizeof(buf)); //12 包括\0
	printf("%d\n", strlen(buf)); // 11
	printf("%d\n", sizeof(bufSize)); //50
	printf("%d\n", strlen(bufSize)); // 11
	printf("%d\n", sizeof(buf2)); //16
	printf("%d\n", strlen(buf2)); // 11
	printf("%d\n", sizeof(buf3)); //9   \123为八进制一个字符83， \\1个字符
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
	strncpy(dest3, src, 20); // 20个字节， 如果20大于src长度，则获取src个字符长度
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
		printf("在%s中查找字符%c\n", str, ch);
		printf("字符串开始位置%u\n", (unsigned int)str);
		printf("查找字符位置%u\n", (unsigned int)search);
		printf("索引位置位置%d\n", search - str);
		printf("索引字符%c\n", *(str + (search - str)));
	}
	else {
		printf("在%s中没有找到字符%c\n", str, ch);
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
		printf("在%s中查找字符%s\n", str, searchStr);
		printf("字符串开始位置%u\n", str);
		printf("查找字符位置%u\n", (unsigned int)searchResult);
		printf("索引位置位置%d\n", searchResult - str);
		printf("索引字符%c\n", *(str + (searchResult - str)));
	}
	else {
		printf("在%s中没有找到字符%s\n", str, searchStr);
	}
	while ((searchResult = strstr(str, searchStr)) && memset(searchResult, '*', strlen(searchStr)));
	printf("%s\n", str);
}

// 字符串转换函数
static void testStrToType() {
	printf("%d\n", atoi("123"));
	printf("%ld\n", atol("12345"));

	char str[20];
	strcpy(str, "3.1415926");
	printf("%.10lf\n", atof(str));

	char buf[128] = "";
	scanf("%s", buf);
	printf("%d\n", my_atoi(buf));

}

static int my_atoi(char *str) {
	// "123"
	int sum = 0;
	while (*str != '\0' && (*str >= '0' && *str <= '9' )) {
		sum = sum * 10 + (*str++) - '0';
		//str++;
	}
	return sum;
}


// 字符串转换函数
static void testMyAtoi() {
	char buf[128] = "";
	scanf("%s", buf);
	printf("%d\n", my_atoi(buf));
}

static void testStrTok() {
	char buf[] = "hehe:haha:xixi:lala";
	char *arr[32] = {NULL};

	// 第一次切割
	int i = 0;

	// 第2~n次切割
	arr[i] = strtok(buf, ":");
	// 保证上一次切割正常
	while (arr[i] != NULL) {
		i++;
		arr[i] = strtok(NULL, ":");
	}
	i = 0;
	while (arr[i] != NULL) {
		printf("%s\n", arr[i]);
		i++;
	}
}

static void testStrTokOpt() {
	char buf[] = "hehe:haha#xixi@lala";
	//char buf[] = "hehe";
	char *arr[32] = { buf, NULL };

	// 第一次切割
	int i = 0;

	// 第2~n次切割
	//arr[i] = strtok(buf, ":");
	// 保证上一次切割正常
	while (arr[i++] = strtok(arr[i], ":#@"));

	i = 0;
	while (arr[i] != NULL) {
		printf("%s\n", arr[i]);
		i++;
	}
}

static void testSprintf() {
	int year = 2022;
	int month = 8;
	int day = 5;
	char buf[] = "";

	sprintf(buf, "%d年%d月%d日", year, month, day);
	printf("%s\n", buf);
}

static void testSscanf() {
	char buf[] = "2020年2月24日";
	int year = 0;
	int month = 0;
	int day = 0;
	char ch = 0;
	char str_year[32] = "";
	char str_month[32] = "";
	char str_day[32] = "";

	sscanf(buf, "%d年%d月%d日", &year, &month, &day);
	printf("year=%d\n",		year);
	printf("month=%d\n",	month);
	printf("day=%d\n",		day);

	sscanf(buf, "%c", &ch);
	printf("ch=%c\n", ch);

	sscanf(buf, "%s年%s月%s日", str_year, str_month, str_day);
	printf("str_year=%s\n", str_year);		// 2020年2月24日
	printf("str_month=%s\n", str_month);// null
	printf("str_day=%s\n", str_day);			// null

	int data1 = 0;
	//sscanf("1234 5678", "1234 %d", &data1); // 5678
	//sscanf("1234 5678", "%*d %d", &data1); // 5678
	//sscanf("1234 5678", "%*s %d", &data1); // 5678  s:空格，\0

	// 提取指定宽度的字符串或数据
	sscanf("12abc5678", "%*5s%d", &data1); // 5678  %*5s配置且丢弃：12abc
	printf("data1=%d\n", data1);

	// %[a-z] 提取a-z的字符
	// %[^a-z] 提取非a-z的字符

	int data2 = 0;
	int data3 = 0;
	sscanf("12345678", "%*2s%2d%*2d%d", &data2, &data3);
	printf("data2=%d\n", data2); // 34
	printf("data3=%d\n", data3); // 78

	char buf2[] = "";
	sscanf("abcDefABC", "%[a-z]", buf2);
	printf("buf2=%s\n", buf2); // abc

	char buf3[] = "";
	sscanf("aaBBcEdef", "%[aBc]", buf3);
	printf("buf3=%s\n", buf3); // aaBBc

	char buf4[] = "";
	sscanf("ABCcABC", "%[^abc]", buf4);
	printf("buf4=%s\n", buf4); // ABC

	char name[] = "";
	char addr[] = "";
	sscanf("wovert@qq.com", "%[^@]%@%[^.]", name, addr);
	printf("id=%s\n", name); // ABC
	printf("addr=%s\n", addr); // ABC


}

void testStrFunc() {
	//testStrLen();
	//testStrCpy();
	//testStrCat();
	//testStrCmp();
	//testStrChr();
	//testStrStr();
	//testStrToType();
	//testMyAtoi();
	//testStrTok();
	//testStrTokOpt();
	//testSprintf();
	testSscanf();
}