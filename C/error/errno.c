#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp = fopen("xxx", "r");
    if (fp == NULL) {
        printf("open file falure!\n");
        printf("errno=%d\n", errno);
        printf("error=%s\n", strerror(errno));
        perror("fopen");

    }
    return 0;
}