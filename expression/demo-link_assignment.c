#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x = 4;
    int y = x = 4;
    printf("x=%i, y=%i\n", x, y);
}
