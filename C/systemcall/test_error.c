#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
  FILE *fp = fopen("txt", "r");
  if (NULL == fp) {
    printf("fopen failed...\n");

    // from error.h
    // from errno-base.h
    // errno 错误号
    printf("errno: %d\n", errno);
    // 错误提示
    printf("%s\n", strerror(errno));

    // 错误提示
    perror("fopen");
  }
  return 0;
}
