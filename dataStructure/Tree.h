#pragma once
#include "common.h"
#include <malloc.h>

#include "TreeStruct.c"

//typedef  char DataType;
BinTNode* CreateTree(char* str) {
	BinTNode* St[100];
	BinTNode* p = NULL;
	int top, k, j = 0;
	top = -1;
	char ch = str[j];
	BinTNode* b = NULL;
	while (ch != '\0') {
		switch (ch)
		{
		case '(':top++;St[top] = p;k = 1;break;
		case ')':top--;break;
		case ',':k = 2;break;
		default:
			p = (BinTNode*)malloc(sizeof(BinTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
			{
				b = p;
			}
			else
			{
				switch (k) {
				case 1:St[top]->lchild = p;break;
				case 2:St[top]->rchild = p;break;
				}
			}
			break;
		}
		j++;ch = str[j];
	}
	return b;
}
