#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[16];
} STD;

int main() {
  FILE *fp = NULL;

  // readable return FILE struct address or return NULL
  fp = fopen("../a.txt", "w");
  // Check exists a.txt file and readable
  if (!fp) {
    perror("fopen");
    return -1;
  }

  fputs("hello world", fp);
  fflush(fp); // flush buffer space
  while(1);

  fclose(fp);
  return 0;
}