#include<iostream>
using namespace std;

#define Maxsize 100  //预先分配空间，这个数值根据实际需要预估确定；

typedef struct SqStack {
	int *base; //栈底指针
	int *top; //栈顶指针
}SqStack;

bool InitStack(SqStack &S) //构造一个空栈S
{
	S.base = new int[Maxsize];//为顺序栈分配一个最大容量为Maxsize的空间
	if (!S.base)    //空间分配失败
		return false;
	S.top=S.base;  //top初始为base，空栈
	return true;
}

bool Push(SqStack &S, int e) // 插入元素e为新的栈顶元素
{
	if (S.top-S.base == Maxsize) //栈满
		return false;
	*(S.top++) = e; //元素e压入栈顶，然后栈顶指针加1，等价于*S.top=e; S.top++;
	return true;
}

bool Pop(SqStack &S, int &e) //删除S的栈顶元素，暂存在变量e中
{
	if (S.base == S.top) //栈空
		return false;
	e = *(--S.top); //栈顶指针减1，将栈顶元素赋给e
	return true;
}

int GetTop(SqStack S) //返回S的栈顶元素，栈顶指针不变
{
	if (S.top != S.base)  //栈非空
		return *(S.top - 1); //返回栈顶元素的值，栈顶指针不变
    else
        return -1;
}

int main()
{
	int n,x;
	SqStack S;
	InitStack(S);//初始化一个顺序栈S
	cout <<"请输入元素个数n：" <<endl;
	cin>>n;
	cout <<"请依次输入n个元素，依次入栈：" <<endl;
	while(n--)
    {
		cin>>x; //输入元素
		Push(S, x);
	}
	cout <<"元素依次出栈：" <<endl;
	while(S.top!=S.base)//如果栈不空，则依次出栈
    {
        cout<<GetTop(S)<<"\t";//输出栈顶元素
        Pop(S, x);   //栈顶元素出栈
    }
	return 0;
}
