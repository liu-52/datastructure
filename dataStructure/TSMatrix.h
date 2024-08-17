//稀疏矩阵-三元组结构
#include "Common.h"
#include <malloc.h>
#define MaxSize 1000
#define MaxRow 1000
typedef struct {
	int i, j; // 非零元素的行号，列号 下标
	DataType v; // 数据
}TriTupleNode;
typedef struct {
	TriTupleNode data[MaxSize];  
	int m,n, t;                  // 行数，列数，非零元素数
}TSMatrix;

typedef struct {
	TriTupleNode data[MaxSize];
	int Row[MaxRow]; //每行第一个非零元素的位置表
	int m, n, t;
}RLSMatrix;

//快速转置算法
void FastTran(TSMatrix a, TSMatrix* b) {
	int col, p, t, q;
	int* num, * rownext; //num[j] 存放第j列非零元素个数，rownext[i] 代表转置矩阵第i行的下一个非零元素在b中的位置
	num = (int*)calloc(a.n + 1, 4);
	rownext = (int*)calloc(a.m + 1, 4);
	b->m = a.n; b->n = a.m; b->t = a.t;
	if (b->t) {
		for (col = 0; col < a.n; ++col)
		{
			num[col] = 0; //初始化
		}
		for (t = 0; t < a.t; ++t) ++num[a.data[t].j]; // 计算每列非零元素数
		rownext[0] = 0;
		for ( col = 0; col < a.n; ++col)
		{
			rownext[col] = rownext[col - 1] + num[col - 1]; // 给出b中每一行的起始点
		}
		for ( p = 0; p < a.t; ++p) //执行转置
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