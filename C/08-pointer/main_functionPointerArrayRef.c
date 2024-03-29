#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RICH_RATE 0.5
#define MIDDLE_RATE 0.1
#define POOR_RATE 0.03

typedef int RATE_FUNC(int *);

int rich(int *);
int middle(int *);
int poor(int *);

RATE_FUNC *funcArr[3] = {NULL};
int prices[3] = {10000, 10000, 10000};

RATE_FUNC *callFunc(int *a) {
  RATE_FUNC *item1 = rich;
  RATE_FUNC *item2 = middle;
  RATE_FUNC *item3 = poor;
//  int (*funcArr[3])(int *) = {item1, item2, item3};
//  RATE_FUNC *funcArr[3] = {item1, item2, item3};
  funcArr[0] = item1;
  funcArr[1] = item2;
  funcArr[2] = item3;

  return funcArr;
}

int rich(int *price) {
  *price *= RICH_RATE;
  return 0;
}
int middle(int *price) {
  *price *= MIDDLE_RATE;
  return 0;
}

int poor(int *price) {
  *price *= POOR_RATE;
  return 0;
}

int main() {
  for(int j=0;j<3; j++) {
    printf("prices[%d]=%d\n", j, prices[j]);
  }

  int (*(*(*pRate)(int *))[3])(int *) = callFunc;


  RATE_FUNC **arr = *pRate(&prices[0]);


  for (int i = 0; i < 3; ++i) {
//    (*(arr[i]))(&prices[i]);
    (*(arr + i))(&prices[i]);
  }
  for(int j=0;j<3; j++) {
    printf("prices[%d]=%d\n", j, prices[j]);
  }

  return 0;
}
