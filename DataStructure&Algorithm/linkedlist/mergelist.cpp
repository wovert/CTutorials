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
	cout <<"请依次输入n个整型数(非递减)：" <<endl;
	cout <<"尾插法创建单链表..." <<endl;
	while(n--)
    {
		s=new LNode;//生成新结点
		cin>>s->data; //输入元素值赋给新结点的数据域
		s->next=NULL;
		r->next=s;//将新结点s插入尾结点r之后
		r=s;//r指向新的尾结点s
	}
}

void mergelinklist(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList p,q,r;
    p=La->next; //p指向La的第一个元素
    q=Lb->next; //q指向Lb的第一个元素
    Lc=La;      //Lc指向La的头结点
    r=Lc;       //r指向Lc的尾部
    while(p&&q)
    {
        if(p->data<=q->data)//把p指向的结点串起来
        {
            r->next=p;
            r=p;
            p=p->next;//p后移一个结点 
        }
        else             //把q指向的结点串起来
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    r->next=p?p:q;//相当于if(p) r->next=p; else r->next=q;
    delete Lb;
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
	LinkList La,Lb,Lc;
	cout << "创建有序（非递减）单链表La:"<<endl;
	CreateList_R(La);
	cout << "创建有序（非递减）单链表Lb:"<<endl;
	CreateList_R(Lb);
	cout << "将两个有序（非递减）单链表La和Lb合并为Lc："<<endl;
	mergelinklist(La,Lb,Lc);
	cout << "合并后的结果Lc："<<endl;
	Listprint_L(Lc);
	return 0;
}

