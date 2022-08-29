#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test_strcpy(void);
void test_strcat(void);
void test_strcmp(void);
void test_strchr(void);
void test_strstr(void);
char* my_strchr(char *str, const char ch);

int main(int argc, char **argv) {
    int i;
    for (i=0; i<argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    // test_strcpy();
    // test_strcat();
    // test_strcmp();
    // test_strchr();
    test_strstr();
    return 0;
}

void test_strstr(void) {
    char str1[128] = "Hello world hello world how";
    char str2[128] = "world";

    // 遇到\0结束比较
    char *p = strstr(str1, str2);
    printf("%s\n", p);

}

// 自定义查找字符
char* my_strchr(char *str, const char ch) {
    int i=0;
    while((str+i) != 0) {
        if (*(str+i) == ch) {
            return str+i;
        }
        i++;
    }
    if ((str+i) == 0) {
        return NULL;
    }
}


// 在字符串中查找指定字符，返回查找的字符的指针，没有找到返回
void test_strchr(void) {
    char str1[128] = "worla\0e you";
    char *p = strchr(str1, 'o');
    printf("%c[%d], %s\n", *p, *p, p);

    char *p1 = strchr(str1, 'k');
    if (p1 == 0) {
        printf("Not find k");
    }
    
    printf("----------------------\n");

    char *p2 = my_strchr(str1, 'r');
    printf("%s\n", p2);
}

void test_strcmp(void) {
    char str1[128] = "worla\0e you";
    char str2[128] = "world\0ok";

    // 遇到\0结束比较
    if (strcmp(str1, str2) == 0) {
        printf("str1==str2\n");
    } else if (strcmp(str1, str2) > 0) {
        printf("str1>str2\n");
    } else {
        printf("str1<str2\n");
    }

    if (strncmp(str1, str2, 4) == 0) {
        printf("str1==str2\n");
    } else if (strcmp(str1, str2) > 0) {
        printf("str1>str2\n");
    } else {
        printf("str1<str2\n");
    }
}

void test_strcat(void) {
    int i;
    char source[128] = "how ar\0e you";
    char dest[128] = "world\0ok";
    char dest2[128] = "abc\0ef";
    char dest3[128] = "xyz\0ef";

    printf("source=%s\n", source);
    printf("dest=%s\n", dest);
    printf("-------------------\n");

    // source遇到\0停止复制i

    // 在dest字符串遇到\0之后追加source的内容中遇到\0之间的内容
    strcat(dest, source); // source附加到dest后面
    printf("source=%s\n", source);
    printf("dest=%s\n", dest);
    printf("-------------------\n");

    strncat(dest2, source, 2);
    printf("dest2=%s\n", dest2);
    printf("-------------------\n");

    strncat(dest3, source, 8);
    printf("dest3=%s\n", dest3);
    
    int dest3_len = strlen(dest3);
    for(i=0;i<dest3_len;i++) {
        printf("dest3[%i]=%c(%d)\n", i, dest3[i], dest3[i]);
    }
    printf("-------------------\n");

}

/**
 * @复制字符串
 * strcpy(目标字符指针, 复制的字符串指针)
 * strncpy(目标字符指针, 复制的字符串指针, 复制字符个数)
 * 
 */
void test_strcpy(void) {
    int i;          
    char str0[128] = "abcdefghijk";
    char str1[128] = "how are you";
    char str2[128] = "world\0ok";
    int str1_len = strlen(str1);
    int str0_len = strlen(str0);

    strcpy(str1, str2); // 会world\0拷贝到str1中
    printf("str1=%s\n", str1);

    // str0复制的长度中包含遇到str2中\0时，会把\0之后的字符变成\0之后复制
    strncpy(str0, str2, 8);
    printf("str0=%s\n", str0);

    printf("----------------\n");
    printf("str0_len=%d\n", str0_len);
    for(i=0;i<str0_len;i++) {
        printf("str0[%i]=%c(%d)\n", i, str0[i], str0[i]);
    }

    strncpy(str0, str2, 11);
    printf("str0=%s\n", str0);
    printf("----------------\n");
    printf("str0_len=%d\n", str0_len);
    for(i=0;i<str0_len;i++) {
        printf("str0[%i]=%c(%d)\n", i, str0[i], str0[i]);
    }


    // strlen 遇到\0停止
    for(i=0;i<strlen(str1);i++) {
        printf("str1[%i]=%c\n", i, str1[i]);
    }


    printf("----------------\n");
    printf("str1_len=%d\n", str1_len);
    for(i=0;i<str1_len;i++) {
        printf("str1[%i]=%c(%d)\n", i, str1[i], str1[i]);
    }


}