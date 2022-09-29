#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <errno.h>


int main() {
  pid_t pid = -1;
  int fd = -1;
  int res = -1;
  void *addr = NULL;

  // 1.创建匿名映射 -1:fd 0:偏移量
  addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  printf("创建匿名映射成功\n");


  // 2.创建子进程
  pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  // child process
  if (0 == pid) {
    // 写文件
    memcpy(addr, "ABCDEFGHIJ", 10);

  } else {
   // parent process
   // 等待子进程结束
   wait(NULL);
   printf("父进程读取 add=%s\n", (char *)addr);
  }


  // 断开存储映射
  munmap(addr, 4096);

  return 0;
}
