#include<iostream>
#include<string>
using namespace std;

typedef struct LNode {
	int data; //结点的数据域
	struct LNode *next; //结点的指针域
}LNode, *LinkList; //LinkList为指向结构体LNode的指针类型

void CreateList_R(LinkList &L)//尾插法创建单链表
{
	//输入n个元素的值，建立带表头结点的单链表L
	int n;
	LinkList s, r;
	L=new LNode;
	L->next=NULL; //先建立一个带头结点的空链表
	r=L; //尾指针r指向头结点
	cout <<"请输入元素个数n：" <<endl;
	cin>>n;
	cout <<"尾插法（正序）创建单链表..." <<endl;
	while(n--)
    {
		s=new LNode;//生成新结点
		cin>>s->data; //输入元素值赋给新结点的数据域
		s->next=NULL;
		r->next=s;//将新结点s插入尾结点r之后
		r=s;//r指向新的尾结点s
	}
}

LinkList findmiddle(LinkList L)
{
	LinkList p,q;
    p=L; //p为快指针，初始时指向L
    q=L; //q为慢指针，初始时指向L
    while(p!=NULL&&p->next!=NULL)
    {
        p=p->next->next;//p为快指针一次走两步；
        q=q->next; //q为慢指针一次走一步
    }
    return q;//返回中间结点指针
}

void Listprint_L(LinkList L) //单链表的输出
{
    LinkList p;
    p=L->next;
    while (p)
    {
        cout<<p->data<<"\t";
		p=p->next;
    }
    cout<<endl;
}

int main()
{
	LinkList L,mid;
	cout<<"创建单链表L:"<<endl;
	CreateList_R(L);
	cout<<"单链表数据为:"<<endl;
	Listprint_L(L);
	mid=findmiddle(L);
	cout<<"单链表中间结点数据为："<<mid->data<<endl;
	return 0;
}

