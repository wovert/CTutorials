#include <iostream>

using namespace std;

typedef int ElementType; 

typedef struct Lnode {
  ElementType data;
  struct Lnode *next;
  struct Lnode *prev;
} Lnode, *LinkList;


bool deleteLnode(Lnode* node) {
    // 不存在下一个节点
    if (!node->next) {
        cout << "delete [" << node->data << "] Lnode" << endl;
        if (node->prev == NULL) {
            cout << "header node" << endl;
            return false;
        }
        Lnode *prevNode = node->prev;
        node->prev->next = NULL; // 上一个节点的下一个节点设为 NULL
        delete node;

        deleteLnode(prevNode);
    } else {
        cout << node->data << "] node has next Node" << endl;
        deleteLnode(node->next);
    }
    return true;
}

int main() {
  // 初始化

  // 头节点
  LinkList list;
  if (!(list = new Lnode())) {
    return 1;
  }

  list->data = 0;
  list->next = NULL;

  // 当前节点
  Lnode *curNode = list;
  for(int i=1; i<=10; i++) {
    Lnode *node;
    if (!(node = new Lnode())) {
        return 1;
    }
    node->data = i;
    node->next = NULL;

    node->prev = curNode;
    node->prev->next = node;
    curNode = node; // 当前节点改为 i节点
  }


  // 删除节点
  deleteLnode(list);
}