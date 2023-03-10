#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[16];
} STD;

int main() {
  FILE *fp = NULL;

  // readable return FILE struct address or return NULL
  fp = fopen("../randomSeek.txt", "w");
  // Check exists a.txt file and readable
  if (!fp) {
    perror("fopen");
    return -1;
  }

  fputs("012345678", fp);
  fseek(fp, 0, SEEK_SET);
  fputs("seek", fp);
  fseek(fp, 0, SEEK_END);
  fputs("append content", fp);
  fseek(fp, -8, SEEK_END);
  fputs(" hi~ ", fp);

  fclose(fp);
  return 0;
}