#include <iostream>

int main()
{

    printf("Hello C!\n");
    system("pause");
    system("cls");
    //system("E:\\download\\logo\\001.png");
    system("color 02"); // green
    /*
      0 = balck
      1 = blue
      2 = green
      3 = 湖蓝色
      4 = red
      5 = puple
      6 = yellow
      7 = white
      8 = gray
      9 = 淡蓝色
      10= 淡绿色
      11= 蓝浅绿色
      12= 淡红色
      13= 淡紫色
      14= 淡黄色
      15= 亮白色
    */
    system("mode con cols=80 lines=40"); // control size
    std::cout << "Hello C++!\n";
    int dec = 123'456;
    int bin = 0b0101;
    int oct = 010;
    int hex = 0Xf;
    std::cout << dec << std::endl;
    std::cout << bin << std::endl;
    std::cout << oct << std::endl;
    std::cout << hex << std::endl;
    system("pause");
    //system("shutdown /s"); // 关机
    //system("shutdown /a"); // 终止关机
}