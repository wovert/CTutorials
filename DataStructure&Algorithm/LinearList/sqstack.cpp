#include<iostream>
using namespace std;

#define Maxsize 100  //Ԥ�ȷ���ռ䣬�����ֵ����ʵ����ҪԤ��ȷ����

typedef struct SqStack {
	int *base; //ջ��ָ��
	int *top; //ջ��ָ��
}SqStack;

bool InitStack(SqStack &S) //����һ����ջS
{
	S.base = new int[Maxsize];//Ϊ˳��ջ����һ���������ΪMaxsize�Ŀռ�
	if (!S.base)    //�ռ����ʧ��
		return false;
	S.top=S.base;  //top��ʼΪbase����ջ
	return true;
}

bool Push(SqStack &S, int e) // ����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top-S.base == Maxsize) //ջ��
		return false;
	*(S.top++) = e; //Ԫ��eѹ��ջ����Ȼ��ջ��ָ���1���ȼ���*S.top=e; S.top++;
	return true;
}

bool Pop(SqStack &S, int &e) //ɾ��S��ջ��Ԫ�أ��ݴ��ڱ���e��
{
	if (S.base == S.top) //ջ��
		return false;
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return true;
}

int GetTop(SqStack S) //����S��ջ��Ԫ�أ�ջ��ָ�벻��
{
	if (S.top != S.base)  //ջ�ǿ�
		return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
    else
        return -1;
}

int main()
{
	int n,x;
	SqStack S;
	InitStack(S);//��ʼ��һ��˳��ջS
	cout <<"������Ԫ�ظ���n��" <<endl;
	cin>>n;
	cout <<"����������n��Ԫ�أ�������ջ��" <<endl;
	while(n--)
    {
		cin>>x; //����Ԫ��
		Push(S, x);
	}
	cout <<"Ԫ�����γ�ջ��" <<endl;
	while(S.top!=S.base)//���ջ���գ������γ�ջ
    {
        cout<<GetTop(S)<<"\t";//���ջ��Ԫ��
        Pop(S, x);   //ջ��Ԫ�س�ջ
    }
	return 0;
}
