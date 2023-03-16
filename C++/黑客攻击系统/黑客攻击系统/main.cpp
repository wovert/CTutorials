#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <mmsystem.h> // mci 播放音乐需要头文件

#pragma comment(lib, "winmm.lib") // 告诉编译器，加载winmm.lib库文件

using namespace std;

void demo01() {
	cout << "1.网站404攻击" << endl;
	cout << "2.网站篡改攻击" << endl;
	cout << "3.网站攻击记录" << endl;
	cout << "4.DNS攻击" << endl;
	cout << "5.服务器传重启攻击" << endl;

	initgraph(640, 480); // 初始化图像界面

// 读取图片至绘图窗口
	loadimage(NULL, _T("bg.png"));

	setbkcolor(RGB(64, 128, 128)); // 设置背景色
	cleardevice(); // 用背景色清空整个屏幕

	// 画一个圆
	setlinecolor(RGB(255, 0, 0)); //设置划线画笔的颜色
	setlinestyle(PS_SOLID, 10); // 实线，宽度为10像素
	circle(320, 240, 200); // 画圆，圆心（320，240） 半径200

	settextcolor(RGB(255, 255, 0)); // 设置字体颜色

	line(180, 380, 460, 100); // 从（180，380）到 (460, 100)画一条直线

	system("pause"); // from Windows.h

	closegraph(); // 关闭图像界面
}

void demo02() {
	initgraph(640, 480); // 初始化图像界面

	// 读取图片至绘图窗口
	loadimage(0, "bg.png");

	mciSendString("play hacker.mp3 repeat", 0, 0, 0); //重复播放 

	settextcolor(RGB(255, 255, 0));      //设置字体颜色
	settextstyle(30, 0, _T("微软雅黑"));

	rectangle(300, 40, 550, 80);     //(左上角x,左上角y, 右下角x，右下角y
	outtextxy(310, 45, _T("1-网站404攻击")); //在指定位置输出文本

	rectangle(300, 100, 550, 140);
	outtextxy(310, 105, _T("2-网站篡改攻击")); //在指定位置输出文本

	rectangle(300, 160, 550, 200);
	outtextxy(310, 165, _T("3-网站攻击修复")); //在指定位置输出文本

	rectangle(300, 220, 550, 260);
	outtextxy(310, 225, _T("4-查看攻击记录")); //在指定位置输出文本

	rectangle(300, 280, 550, 320);
	outtextxy(310, 285, _T("5-退出")); //在指定位置输出文本

	system("pause");
	closegraph();			   // 关闭图形界面

}
int main() {


	//demo01();
	demo02();
	return 0;
}