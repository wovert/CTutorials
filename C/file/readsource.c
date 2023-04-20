#include <stdio.h>
#include <string.h>


int main() {
  char *srcImageFile = "../main.c";

  FILE *srcFileStream;

  srcFileStream = fopen(srcImageFile, "rb");
  if (srcFileStream == NULL) {
    perror("open");
    return -1;
  }

  char c;
  while(1) {
    c = fgetc(srcFileStream);
    if (feof(srcFileStream)) // file end=
        break;
    fputc(c, stdout);
  }

  fclose(srcFileStream);

  return 0;
}