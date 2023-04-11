#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>

#define SIZE 128

int main() {

  int fds[2];
  int res = -1;
  pid_t pid = -1;
  char buf[SIZE];

  // create no name channel
  res = pipe(fds);
  if (-1 == res) {
    perror("pipe");
    return 1;
  }

  pid = fork();
  if (-1 == pid) {
    perror("fork");
    return 1;
  }

  // child process: read channel
  if (0 == pid) {
    // close write
    close(fds[1]);

    printf("Child process read content from pipe\n");


    memset(buf, 0, SIZE);

    // set nonblock
    res = fcntl(fds[0], F_GETFL);
    res |= O_NONBLOCK;
    fcntl(fds[0], F_SETFL, res);

    // read from channel: wait for parent write into channel => block
    res = read(fds[0], buf, SIZE);

   if (res < 0) {
     printf("read error\n");
     perror("read");
     exit(-1);
   }

  // view buffer pipe size
  printf("fds[0]=%d, pipe size :%ld\n", fds[0], fpathconf(fds[0], _PC_PIPE_BUF));
  printf("fds[1]=%d, pipe size :%ld\n", fds[1], fpathconf(fds[1], _PC_PIPE_BUF));




   printf("child process buf:%s\n", buf);

    // close read
    close(fds[0]);
    exit(0);
  }

  // Parent process
  // close read
  close(fds[0]);

  sleep(3);

  // write channel
  res = write(fds[1], "abcde12345", 10);
  if (res < 0) {
    perror("write");
    return 1;
  }


  printf("Parent process write len:%d\n", res);

  // fd[0]:read    fd[1]: wirte
  //printf("fds[0]: %d fds[1]: %d\n", fds[0], fds[1]);

  // close write
  close(fds[1]);

  return 0;
}
