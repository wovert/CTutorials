#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test_sprintf(void);
void test_sscanf(void);

int main(int argc, char* argv[]) {
    // test_sprintf();
    test_sscanf();
    return 0;
}

// 拆包
void test_sscanf(void) {
    int year = 0;
    int month = 0;
    int day = 0;
    char buf[1024] = "2022-08-30";
    // scanf("%4d %2d %2d", &year, &month, &day);
    
    printf("----------\n");
    sscanf(buf, "%d-%d-%d", &year, &month, &day);
    printf("%4d:%02d:%2d\n", year, month, day);

}

// 组包
void test_sprintf(void) {
    int year = 2022;
    int month = 8;
    int day = 29;
    char buf[1024] = "";
    int len = sprintf(buf, "year=%d %c month=%d day=%d\n", year, 0, month, day);
    printf("buf=%s\n", buf); // buf=year=2022
    printf("len=%d\n", len); // 27
    printf("strlen(buf)=%d\n", strlen(buf)); // 10

    int i;
    for(i=0; i<len; i++) {
        printf("buf[%d]=%c[%d]\n", i, buf[i], buf[i]);
    }
}