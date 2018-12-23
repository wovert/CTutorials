#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int card = 1;
    if (card > 1) {
        card = card - 1;
        if (card < 7)
            puts("小牌");
    } else
        puts("Ace!");
    
    return 0;
}
