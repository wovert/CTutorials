#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>



int main() {
  pid_t pid = -1;
  int fd = -1;
  int res = -1;
  void *addr = NULL;

  // 读写方式打开一个文件
  fd = open("./txt", O_RDWR);
  if (-1 == fd) {
    perror("open");
    return 1;
  }

  // 将文件映射到内存
  addr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  printf("文件存储映射成功\n");

  close(fd);

  // 读文件
  printf("add=%s\n", (char *)addr);

  // 断开存储映射
  munmap(addr, 1024);

  return 0;
}
