#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
 

    // child process
    printf("start...\n");
    // 等价于 return 0;
    exit(110);
    // _exit(0) // 直接退出，不做任何清理工作
    // _Exit(0) == _exit(0)
    printf("end...\n");
  
  return 0;
}
