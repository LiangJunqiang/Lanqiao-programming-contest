#include <stdio.h>
#include <memory.h>
#define MAX	200
void juzhenmultiply(int A[][MAX], int B[][MAX], int m, int s, int n)
{
	int C[MAX][MAX];
	int i, j, k, l;
	memset(C, 0, sizeof(C));
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < s; k++)
				C[i][j] += A[i][k] * B[k][j];
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++)
			printf("%d ", C[i][j]);
		putchar('\n');	
	}
}
int main()
{
	int m, s, n;
	int A[MAX][MAX], B[MAX][MAX];
	int i, j;
	scanf("%d%d%d", &m, &s, &n);
	for(i = 0; i < m; i++)
		for(j = 0; j < s; j++)
			scanf("%d", &A[i][j]);
	for(i = 0; i < s; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	juzhenmultiply(A, B, m, s, n);
	return 0;
}
