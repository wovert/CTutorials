#include <stdio.h>
#include <string.h>

static void readCharFile() {
  FILE *fp = NULL;
  char buf[128] = "";
  int i = 0;

  // readable return FILE struct address or return NULL
  fp = fopen("../a.txt", "r");

  // Check exists a.txt file and readable
  if (fp == NULL) {
    perror("fopen");
    return;
  }

  char c;
  // EOF == -1
//  while ((c = fgetc(fp)) != EOF) {
//    buf[i] = c;
//    printf("%c=%d\n", buf[i], buf[i]);
//    i++;
//  }

  do {
    buf[i] = fgetc(fp);
    i++;
  } while(!feof(fp)); // feof ·µ»Ø ·Ç0

  printf("buf=%s, strlen(buf)=%d sizeof(buf)=%d \n", buf, strlen(buf), sizeof(buf));

  fclose(fp);
}

static void writeCharFile() {
  FILE *fp = NULL;
  char buf[5] = "";
  int i = 0;

  fp = fopen("../write.txt", "w");
  if (fp == NULL) {
    perror("fopen");
    return;
  }

  // csontain \0
  printf("Please input %d char text\n", sizeof(buf));
  fgets(buf, sizeof(buf), stdin);

  printf("length %d\n", strlen(buf));
  printf("siezof %d\n", sizeof(buf));

  if (strlen(buf) + 1 != sizeof(buf)) {
    buf[strlen(buf) - 1] = 0; // trim last \n character
  }

  // 0 == '\0'
  while (buf[i] != '\0') {
    fputc(buf[i], fp);
    i++;
  }

  // close file stream
  fclose(fp);
}

static void writeStringFile() {
  FILE *fp = NULL;
  char *buf[] = {"01\n", "02\n", "03\n"};
  int n = sizeof(buf) / sizeof(buf[0]);
  int i = 0;

  fp = fopen("../a.txt", "w");
  if (fp == NULL) {
    perror("fopen");
    return;
  }

  for (i = 0; i < n; i++) {
    fputs(buf[i], fp);
  }

  fclose(fp);
}

static void readStringFile() {
  FILE *fp = NULL;
  char buf[128] = "";
  int i = 0;

  char *path = "../a.txt";
  fp = fopen(path, "r");
  if (fp == NULL) {
    perror("fopen");
    return;
  }


  while (fgets(buf, sizeof(buf), fp) != NULL) {
    printf("%s", buf);
  }

  fclose(fp);
}

int main() {
  readCharFile();
//  writeCharFile();
//  writeStringFile();
  readStringFile();
  return 0;
}