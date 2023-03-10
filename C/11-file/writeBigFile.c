#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[16];
} STD;

int main() {
  FILE *fp = NULL;

  // readable return FILE struct address or return NULL
  fp = fopen("../bigfile.txt", "r");
  // Check exists a.txt file and readable
  if (!fp) {
    perror("fopen");
    return -1;
  }

  STD stdNums[3];
  memset(stdNums, 0, sizeof(stdNums));

  // param 1: read pointer data
  // param 2: element size
  // param 3: element count
  // param 4: file pointer
  // return: write into file char count
  int count;
  for(int i=0; i<3;i++) {
    count = fread(&stdNums[i], 1, sizeof(STD), fp);
    printf("count=%d id=%d name=%s\n", count, stdNums[i].id, stdNums[i].name);
  }

  fclose(fp);
  return 0;
}