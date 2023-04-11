#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 128

int main() {

  int fds[2]; // [0] read [1] write
  int res = -1;
  pid_t pid = -1;
  char buf[SIZE];

  // create unname channel
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

    // init space size
    memset(buf, 0, SIZE);

    // read from channel: wait for parent write into channel => block
    res = read(fds[0], buf, SIZE);

    // check read
    if (res < 0) {
      perror("read");
      exit(-1);
    }

    // fpathconf: view pipe buffer size
    printf("In Child Process fds[0]=%d, pipe size :%ld\n", fds[0], fpathconf(fds[0], _PC_PIPE_BUF));
    printf("In Child Process fds[1]=%d, pipe size :%ld\n", fds[1], fpathconf(fds[1], _PC_PIPE_BUF));


    printf("child process buf:%s\n", buf);

    // close read
    close(fds[0]);
    exit(0);
  }

  // Parent process
  printf("Parent process start\n");

  // close read
  close(fds[0]);

  // write channel
  res = write(fds[1], "abcde12345", 10);
  if (res < 0) {
    perror("write");
    return 1;
  }


  printf("Parent process write len:%d\n", res);

  // fd[0]:read    fd[1]: wirte
  printf("In Parent process fds[0]: %d fds[1]: %d\n", fds[0], fds[1]);

  // close write
  close(fds[1]);

  return 0;
}
