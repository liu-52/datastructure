#include "BinTree.c"
#include<stdio.h>

int main() {

	//LinkList list;
	//list = CreateListF();
	//printf_s("%c", list->data);
	/*BinTNode *bin;
	char* c;
	c = "(A(B(,D(E,F)),C))";
	bin = CreateTree(c);
	printf_s("%c", bin->data);*/
	BinTree b;
	b = NULL;
	BinTree bt =  CreateBinTree(b);
	printf("%c", bt->data);
	return 0;
}