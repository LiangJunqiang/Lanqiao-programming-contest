#include "stdio.h"
#define MAXNUM 1002
typedef int ElemNum;
void sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int key = array[left];
	
	while (i < j) {
		for (; key <= array[j] && j > i; --j)
			;
		array[i] = array[j];
		for (; key >= array[i] && j > i; ++i)
			;
		array[j] = array[i];
	}
	array[i] = key;
	if(i + 1 < right)
		sort(array, i + 1, right);
	if(left < i - 1)
		sort(array, left, i - 1);
}
ElemNum intersection(int A[], int B[], int C[], int n, int m)
{	//求A和B的交集，存放于C中，并返回交集的元素个数
	int i, j = 0;
	for (i = 0; i < m; ++i)
	{
		if(InGather(B[i], A, n)){
			C[j] = B[i];
			j++;
		}
	}
	return j;
}//intersection
ElemNum And(int A[], int B[], int C[], int n, int m)
{	//求A和B的并集，存放于C中，并返回并集的元素个数
	int i, j = 0;
	for (i = 0; i < n; ++i, ++j)
		C[j] = A[i];
	for(i = 0; i < m; ++i){
		if(!InGather(B[i], C, j)){
			C[j] = B[i];
			j++;	
		}
	}
	return j;
}//And
ElemNum ComplementarySet(int A[], int B[], int C[], int n, int m)
{	//求A和B的余集，存放于C中，并返回余集的元素个数
	int i, j = 0;
	for (i = 0; i < n; ++i)
	{
		if(!InGather(A[i], B, m)){
			C[j] = A[i];
			j++;	
		}
	}
	return j;
}//ComplementarySet
int InGather(int x, int Y[], int n)
{	//数组Y是否包含x元素
	int i;
	for (i = 0; i < n && x != Y[i]; ++i)
		;
	if(i < n)
		return 1;
	else
		return 0;
}//InGather
int main(int argc, char const *argv[])
{
	int n, m;
	int A[MAXNUM], B[MAXNUM];
	int C[MAXNUM * 2];
	int i, num;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	for (i = 0; i < m; ++i)
		scanf("%d", &B[i]);
	num = intersection(A, B, C, n, m);
	sort(C, 0, num - 1);
	for (i = 0; i < num; ++i)
		printf("%d ", C[i]);
	putchar('\n');
	num = And(A, B, C, n, m);
	sort(C, 0, num - 1);
	for (i = 0; i < num; ++i)
		printf("%d ", C[i]);
	putchar('\n');
	num = ComplementarySet(A, B, C, n, m);
	sort(C, 0, num - 1);
	for (i = 0; i < num; ++i)
		printf("%d ", C[i]);
	putchar('\n');
	return 0;
}//main
