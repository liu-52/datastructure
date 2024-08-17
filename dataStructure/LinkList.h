
#include <malloc.h>
#include "Common.h"

typedef struct node {
	DataType data;
	struct node* next;
} ListNode;
typedef ListNode * LinkList;
ListNode* p;
//LinkList head;

LinkList CreateListF() {
	LinkList head;
	ListNode* p;
	char ch;
	ch = getchar();
	head = NULL;
	while (ch!='\n')
	{
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;
		p->next = head;
		head = p;
		ch = getchar();
	}
	return head;
}