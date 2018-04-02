#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char line[80];
  FILE *in;
  
  if (!(in = fopen("spooky.csv", "r"))) {
    return 1;
  }
  FILE *f1 = fopen("ufo.csv", "w");
  FILE *f2 = fopen("dis.csv", "w");
  FILE *f3 = fopen("other.csv", "w");
  while (fscanf(in, "%79[^\n]\n", line) == 1) {
    if (strstr(line, "ufo")) {
      fprintf(f1, "%s\n", line);
    } else if(fscanf(line, "dis")) {
      fprintf(f2, "%s\n", line);
    } else if(fscanf(line, "other")) {
      fprintf(f3, "%s\n", line);
    }
  }
  //fclose(in);
  fclose(f1);
  fclose(f2);
  fclose(f3);

}