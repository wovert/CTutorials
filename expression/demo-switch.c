#include <stdio.h>

int main(int argc, const char * argv[]) {

    int x = 2, y=3;
    switch(x) {
        default:
            y++;
        
        case 3:
            y++;
            break;
        
        case 4:
            y++;
    }
    printf("y=%i\n", y); // 5, 首先根据选择情况是x是2,没有找到case是2的选项,所以找到default执行y++,又因为没有遇到break所以产生case穿透,继续往下执行,遇到break跳出,最后y变为5
}
