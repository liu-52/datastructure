//ϡ�����-��Ԫ��ṹ
#include "Common.h"
#include <malloc.h>
#define MaxSize 1000
#define MaxRow 1000
typedef struct {
	int i, j; // ����Ԫ�ص��кţ��к� �±�
	DataType v; // ����
}TriTupleNode;
typedef struct {
	TriTupleNode data[MaxSize];  
	int m,n, t;                  // ����������������Ԫ����
}TSMatrix;

typedef struct {
	TriTupleNode data[MaxSize];
	int Row[MaxRow]; //ÿ�е�һ������Ԫ�ص�λ�ñ�
	int m, n, t;
}RLSMatrix;

//����ת���㷨
void FastTran(TSMatrix a, TSMatrix* b) {
	int col, p, t, q;
	int* num, * rownext; //num[j] ��ŵ�j�з���Ԫ�ظ�����rownext[i] ����ת�þ����i�е���һ������Ԫ����b�е�λ��
	num = (int*)calloc(a.n + 1, 4);
	rownext = (int*)calloc(a.m + 1, 4);
	b->m = a.n; b->n = a.m; b->t = a.t;
	if (b->t) {
		for (col = 0; col < a.n; ++col)
		{
			num[col] = 0; //��ʼ��
		}
		for (t = 0; t < a.t; ++t) ++num[a.data[t].j]; // ����ÿ�з���Ԫ����
		rownext[0] = 0;
		for ( col = 0; col < a.n; ++col)
		{
			rownext[col] = rownext[col - 1] + num[col - 1]; // ����b��ÿһ�е���ʼ��
		}
		for ( p = 0; p < a.t; ++p) //ִ��ת��
		{
			col = a.data[p].j;
			q = rownext[col];
			b->data[q].i = a.data[p].j;
			b->data[q].j = a.data[p].i;
			b->data[q].v = a.data[p].v;
			++rownext[col]; 
		}
	}
}