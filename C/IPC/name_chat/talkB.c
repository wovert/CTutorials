#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 128

// first write after read
// only write open pipe
// only read open pipe
int main() {
  int fdr = -1;
  int fdw = -1;
  int res = -1;
  char buf[SIZE];

  // 只写的方式打开管道1
  fdw = open("./fifo1", O_WRONLY);
  if (-1 == fdw) {
    perror("open");
    return 1;
  }
  printf("以只写的方式打开管道1...\n");

  // 只读的方式打开管道2
  fdr = open("./fifo2", O_RDONLY);
  if (-1 == fdr) {
    perror("open");
    return 1;
  }

  printf("以只读的方式打开管道2...\n");




  // loop read write
  while (1) {
    // 写管道1
    memset(buf, 0, SIZE);
    // block
    fgets(buf, SIZE, stdin);
    // 去掉最后一个换行符
    if ('\n' == buf[strlen(buf) - 1]) {
      buf[strlen(buf) - 1] = '\0';
    }
    res = write(fdw, buf, strlen(buf));
    if (res <= 0) {
      perror("write");
      break;
    }
    printf("write res:%d\n", res);
    
    // 清0
    memset(buf, 0, SIZE);
    // 读管道2 block
    res = read(fdr, buf, SIZE);
    if (res <= 0) {
      perror("read");
      break;
    }
    printf("read:%s\n", buf);

  }


  close(fdr);
  close(fdw);

  return 0;
}
