#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// 进程相关
#include <unistd.h>

int main() {
  pid_t pid = -1;
  int status = 0;
  int i;
  int res = -1;

  pid = fork();

  if (-1 == pid) {
  	perror("fork");
	return 1;
  }
  
  if (pid == 0) {
    // child process
    for (i=0; i<20; i++) {
      printf("Run child process pid=%d %d\n", getpid(), i+1);
      sleep(1); // wait 1 seconds
    }
    exit(10);
  } 
  
  printf("Parent wait child exit\n");
  // parent process block wait for child process exit
  //res = wait(&status);
  //res = waitpid(-1, &status, 0); // equal wait()
  res = waitpid(-1, &status, WNOHANG); // nonblock
  if (res == -1) {
    perror("wait");
    return 1;
  }
  printf("Parent get from child process resource\n");
 
  // normal exit
  if (WIFEXITED(status)) {
    printf("Child process exit status code: %d\n", WEXITSTATUS(status));
  } else if (WIFSIGNALED(status)) {
    // kill [-9] PID
    printf("Child process signal %d killed\n", WTERMSIG(status));
  } else if (WIFSTOPPED(status)) {
    // kill -19 PID    stop signal
    // kill -18 PID    continue signal
    printf("Child process signal %d stopped\n", WSTOPSIG(status));
  }


  return 0;
}
