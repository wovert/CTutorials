#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <error.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SIZE 128

int main() {
  int i = 0;
  int fd = -1;
  int res = -1;
  char buf[SIZE];
  

  // 1. Only write type open pipe file
  fd = open("./fifo", O_RDONLY);
  if (-1 == fd) {
    perror("open");
    return 1;
  }

  // 2. write pipe
  printf("Only read type open a pipe ...\n");
  
  while (1) {
    memset(buf, 0, SIZE);
    // block
    res = read(fd, buf, SIZE);
    if (res <= 0) {
      perror("read");
      break;
    }
    printf("buf fifo:%s\n", buf);
  }

  printf("read file close fd\n");
  // 3. close file
  close(fd);

  return 0;
}
