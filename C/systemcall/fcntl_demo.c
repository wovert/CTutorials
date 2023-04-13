#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 128


// 复制文件描述符
int main(void) {

  int fd = -1;
  int newfd = -1;

  fd = open("txt", O_WRONLY | O_CREAT, 0644);
  if (-1 == fd) {
    perror("open");
    return 1;
  }

  printf("fd=%d\n", fd);

  // 2. 文件描述符复制
  // 参数0: 返回一个最小可用的文件描述符，并且大于或者等于0
  // 功能等价于dup函数
  newfd = fcntl(fd, F_DUPFD, 0);
  if (-1 == newfd) {
    perror("fcntl");
    return 1;
  }

  printf("newfd=%d\n", newfd);

  // 3. 写文件
  write(fd, "abcdefg", 7);
  write(newfd, "1234567", 7);


  // 4. 关闭文件
  close(fd);
  close(newfd);

  return 0;
}
