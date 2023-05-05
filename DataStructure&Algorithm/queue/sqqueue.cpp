#include <iostream>
using namespace std;
#define Maxsize 100

typedef  struct SqQueue{
  int *base; //基地址
  int front,rear; //头指针,尾指针
}SqQueue;

//循环队列的初始化
bool InitQueue(SqQueue &Q)//注意使用引用参数，否则出了函数，其改变无效
{
	Q.base=new int[Maxsize];//分配空间
	if(!Q.base) return false;
	Q.front=Q.rear=0; //头指针和尾指针置为零，队列为空
	return true;
}

//循环队列的入队
bool EnQueue(SqQueue &Q,int e)//将元素e放入Q的队尾
{
	if((Q.rear+1)%Maxsize==Q.front) //尾指针后移一位等于头指针，表明队满
		return false;
	Q.base[Q.rear]=e; //新元素插入队尾
	Q.rear=(Q.rear+1)%Maxsize; //队尾指针加1
	return true;
}

//循环队列的出队
bool DeQueue(SqQueue &Q, int &e) //删除Q的队头元素，用e返回其值
{
	if (Q.front==Q.rear)
		return false; //队空
	e=Q.base[Q.front]; //保存队头元素
	Q.front=(Q.front+1)%Maxsize; //队头指针加1
	return true;
}

//取循环队列的队头元素
int GetHead(SqQueue Q)//返回Q的队头元素，不修改队头指针
{
	if (Q.front!=Q.rear) //队列非空
		return Q.base[Q.front];
    return -1;
}
//循环队列的长度
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+Maxsize)%Maxsize;
}

int main()
{
	SqQueue Q;
	int n,x;
	InitQueue(Q);//初始化队列(一定要初始化，否则后面存储出错)
	cout <<"请输入元素个数n：" <<endl;
	cin>>n;
	cout <<"请依次输入n个整型数，依次入队：" <<endl;
    while(n--)
    {
       	cin>>x;
		EnQueue(Q,x);//入队
    }
    cout<<endl;
    cout <<"队列内元素个数，即长度："<<QueueLength(Q)<<endl;
    cout <<"队头元素：" <<GetHead(Q)<<endl;
	cout <<"元素依次出队：" <<endl;
	while(true)//如果栈不空，则依次出栈
    {
        if(DeQueue(Q,x))
            cout<<x<<"\t";//出队元素
        else
            break;
    }
    cout <<endl;
    cout <<"队列内元素个数，即长度："<<QueueLength(Q)<<endl;
	return 0;
}
