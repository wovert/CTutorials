#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char data[128];
	struct NODE *next;
} NODE;

// 静态链表
static void staticLink() {
	NODE *head = NULL;
	NODE *pb = NULL;

	NODE n0 = { 0, "node0" };
	NODE n1 = { 1, "node1" };
	NODE n2 = { 2, "node2" };
	NODE n3 = { 3, "node3" };
	NODE n4 = { 4, "node4" };
	NODE n5 = { 5, "node5" };

	head = &n0;
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;

	pb = head;

	while (pb != NULL) {
		printf("%d %s\n", pb->id, pb->data);
		pb = pb->next; // pb指向下一个节点
	}
}

// 动态链表
static void dynamicLink() {

}

void testLink() {
	//staticLink();
	dynamicLink();
}