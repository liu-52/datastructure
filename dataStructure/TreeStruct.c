#include "Common.h"
typedef struct node {
	DataType data;
	struct node* lchild, * rchild;
} BinTNode;
typedef BinTNode* BinTree;