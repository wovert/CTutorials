#include <stdio.h>

void test() {
    // 初始化：逐个字符初始化 不推荐
    // char str[6] = {'h','e','l','l','o'};
    // str[0] = 'h' 的 ASCII 值
    // 初始化：以字符串的形式 初始化 推荐
    char str[6] = "hello";

    // 逐个字符遍历
    for(int i=0; i<6; i++) {
        printf("%c", str[i]);
    }
    printf("\n-----------\n");

    // 字符数组 可以整体遍历 推荐
    printf("%s\n", str);

    printf("第0个元素的地址：%p\n", &str[0]);
    printf("数组的地址：%p\n", str);
}

void compareArrayString() {
    char str1[] = {'h','e','h','e'}; // 逐个字符初始化 系统不会添加 '\0'
    char str2[] = "hehe"; // 以字符串初始化 系统会给字符串添加 '\0'

    // 空间大小
    printf("sizeof(str1)=%d\n", sizeof(str1)); //4
    printf("sizeof(str2)=%d\n", sizeof(str2)); //5

    // %s输出的内容: 从数组的第0个元素开始逐个元素输出 直到遇到'\0'结束
    printf("str1=##%s##\n", str1);
    printf("str2=##%s##\n", str2);
}

// 获取键盘的字符串：定义一个字符数组 有足够大的空间
void charArray() {
    char buf[10] = "";
    printf("请输入一个字符串\n");

    // scanf 和 %s 使用时遇到空格会结束输入
    // scanf("%s", &buf); // 不能获取带空格的字符
    //gets(buf); // 获取带空格的字符串 缺点：不会管 buf 的大小 容易造成内存污染

    // fgets函数，既可以带空格的字符串也保证buf 不越界
    // $ man fgets
    // s: 存放字符串的空间地址, size:能够提取字符串的最大长度 size-1(函数内部减去1)
    // char *fgets(char *s, int size, FILE *stream)
    printf("sizeof(buf)=%d\n", sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    // 逐个字符遍历
    for(int i=0; i<sizeof(buf); i++) {
        printf("%c", buf[i]);
    }

    printf("buf=%s\n", buf);
}

void arrayLevel2() {
    // & 取地址运算符

    // & reference 引用 <=> * dereference 解引用

    // &arr[0] 解引用得到 arr, arr解引用得到 arr[0]

    // 一维数组的数组名，是一级指针，二维数组的数组名，是数组指针
    int arr[3][4] = {{},{1,2,3,4},{}}; // int[4] arr[3]
    printf("arr = %p\n", arr);  // 起始地址
    printf("&arr[0] = %p\n", &arr[0]);
    printf("arr = %p arr+1 = %p\n", arr, arr+1); // 步长 16

    printf("arr[0] = %p\n", arr[0]);
    printf("&arr[0][0] = %p\n", &arr[0][0]);
    printf("arr[0] = %p arr[0]+1 = %p\n", arr[0], arr[0]+1); // 步长 4

    printf("\n----------------------\n");

    printf("arr = %p\n", arr);
    printf("arr+1 = %p\n", arr+1); // 步长 16
    // 对arr解引用
    printf("*arr = %p\n", *arr);
    printf("*arr+1 = %p\n", *arr+1); // 步长 4

    // *(arr+1) 二维数组的第2个元素地址
    // *(*(arr+1)+2) 二维数组的第2个元素地址的第3个元素地址
     printf("&(*(*(arr+1)+2)) = %p\n", &(*(*(arr+1)+2))); // 步长 24
    printf("*(*(arr+1)+2) = %d\n", *(*(arr+1)+2)); // 3
}

int main(int argc, char *argv[])
{
    //test();
    // compareArrayString();
    // getchar();
    // charArray();
    arrayLevel2();
    return 0;
}
