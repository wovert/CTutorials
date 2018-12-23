#include <stdio.h>

int main(int argc, const char * argv[]) {

    char *pCards1 = "JQK";
    const char *pCards2 = "JQK";
    const char *pCards3 = "JQK";

    *(pCards1+1) = 'A'; // 能编译通过，但执行程序出错
    *(pCards2+1) = 'A'; // 直接提示不能编译
    
    char cards[] = "JQK";
    cards[0] = 'A';
    
    printf("cards=%s, %p\n", cards, cards);
    printf("cards1=%s, %p\n", pCards1, pCards1);
    printf("cards2=%s, %p\n", pCards2, pCards2);
    printf("cards3=%s, %p\n", pCards3, pCards3);

}
