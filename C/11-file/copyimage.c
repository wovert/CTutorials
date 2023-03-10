#include <stdio.h>
#include <string.h>


int main() {
  char *srcImageFile = "../duo.png";
  char *destImageFile = "../dest.png";

  FILE *srcFileStream;
  FILE *destFileStream;

  srcFileStream = fopen(srcImageFile, "rb");
  if (srcFileStream == NULL) {
    perror("open");
    return -1;
  }

  destFileStream = fopen(destImageFile, "wb");
  if (destFileStream == NULL) {
    perror("open");
    return -1;
  }

  char c;
  while(1) {
    c = fgetc(srcFileStream);
    if (feof(srcFileStream)) // file end=
        break;
    fputc(c, destFileStream);
  }

  fclose(srcFileStream);
  fclose(destFileStream);

  return 0;
}