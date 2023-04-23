#include <iostream>

using namespace std;

typedef int ElementType;

const int MAX_SIZE = 6;

typedef struct SeqStack {

  // 动态分配
  ElementType *base;  // 栈底
  ElementType *top;   // 栈顶


  // 静态分配
  ElementType data[MAX_SIZE];   // 定长数组
  int indexTop;                 // 栈顶下标

} SeqStack, *SeqStackPtr; // 类型名

int main() {
  // 初始化
  SeqStackPtr s;
  s = new SeqStack;
  if (!s) {
    cout << "new s failed" << endl;
    return -1;
  }
  s->base = new ElementType[MAX_SIZE];
  if (!s->base) {
    cout << "new ElementType failed" << endl;
    return -1;
  }
  s->top = s->base;

  // 入栈
  for(int i=1; i<=10; i++) {
    if (s->top - s->base == MAX_SIZE) {
      cout << "stack full" << endl;
      break;
    }
    *(s->top)++ = i; // 将10 压栈，然后栈顶指针+1
  }

  // 打印
  cout << *(s->top) << endl;
  cout << *(s->top-1) << endl; 
  cout << *(s->top-2) << endl; 
  cout << *(s->top-3) << endl; 
  cout << "---------" << endl;

  // 弹栈
  *(--s->top) = 0;

  // 打印
  cout << *(s->top) << endl; 
  cout << *(s->top-1) << endl; 
  cout << *(s->top-2) << endl; 
  cout << *(s->top-3) << endl; 
  cout << "---------" << endl;
  
  delete [] s->base;
  s = NULL;

  cout << "----end-----" << endl;
  return 0;
}