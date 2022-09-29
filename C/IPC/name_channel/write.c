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
  
  if (access("./fifo", F_OK) != 0) {
    res = mkfifo("./fifo", 0644);
    if (-1 == res) {
      perror("mkfifo");
      return 1;
    }
    printf("create name pipe file successful!\n");
  }

  // 1. Only write type open pipe file
  fd = open("./fifo", O_WRONLY);
  if (-1 == fd) {
    perror("open");
    return 1;
  }

  // 2. write pipe
  printf("Only write type open a pipe ...\n");
  
  while (1) {
    memset(buf, 0, SIZE);
    sprintf(buf, "hello world %d", i++);
    res = write(fd, buf, strlen(buf));
    if (res <= 0) {
      perror("write");
      break;
    }
    printf("write fifo:%d\n", res);
    sleep(1);
  }

  // 3. close file
  close(fd);

  return 0;
}
