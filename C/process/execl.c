#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Hello world\n");

  execl("/bin/ls", "ls", "-l", "/home", NULL);

  printf("End main function\n");
}
