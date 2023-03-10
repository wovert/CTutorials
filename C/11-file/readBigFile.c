#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[16];
} STD;

int main() {
  FILE *fp = NULL;

  // readable return FILE struct address or return NULL
  fp = fopen("../bigfile.txt", "w");
  // Check exists a.txt file and readable
  if (!fp) {
    perror("fopen");
    return -1;
  }

  STD stdNums[3] = {{1, "lucsy"},{2, "bob"},{3, "cat"}};

  // param 1: read pointer data
  // param 2: element size
  // param 3: element count
  // param 4: file pointer
  // return: write into file char count
  int charCount = fwrite(stdNums, 1, sizeof(stdNums), fp);
  printf("charCount=%d\n", charCount);

  fclose(fp);
  return 0;
}