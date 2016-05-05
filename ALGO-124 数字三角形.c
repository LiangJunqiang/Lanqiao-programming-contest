#include <stdio.h>
#include <string.h>
#define NUM (1+100)*100/2
int k(int i, int j);
int main()
{
	int A[NUM], row, B[NUM];
	int i, j, p;
	int num;
	scanf("%d", &row);
	num = (1 + row) * row / 2;
	for(i = 0; i < num; i++){
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	B[1] += A[0];
	B[2] += A[0];
	for(i = 2; i < row; i++)
		for(j = 0; j <= i; j++)
		{
			p = k(i, j);
			if(j == 0)
				B[p] += B[k(i - 1, j)];
			else if(j == i)
				B[p] += B[k(i - 1, j - 1)];
			else
				B[p] += ((B[k(i - 1, j)] >= B[k(i - 1, j - 1)]) ? B[k(i - 1, j)] : B[k(i - 1, j - 1)]);
		}
	i = k(row - 1, 0);
	j = B[i];
	for(p = i + 1; p < num; p++)
	{
		if(B[p] > j)
			j = B[p];
	}
	printf("%d\n", j);
	return 0;
}
int k(int i, int j)
{
	return ((1 + i) * i / 2 + j);
}




