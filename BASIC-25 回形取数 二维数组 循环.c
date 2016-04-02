#include "stdio.h"
#define MAXLEN	202
void roundread(int x[][MAXLEN], int m, int n)
{
	int i = 0, j = 0, m1 = -1, n1 = -1;
	while(m > m1 + 1 && n > n1 + 1){
		while(i < m && i > m1 && j < n && j > n1){
			printf("%d ", x[i][j]);
			i++;
		}
		i--;
		j++;
		n1++;
		while(j < n && j > n1 && i > m1 && i < m){
			printf("%d ", x[i][j]);
			j++;
		}
		j--;
		i--;
		m--;
		while(i > m1 && i < m && j < n && j > n1){
			printf("%d ", x[i][j]);
			i--;
		}
		i++;
		j--;
		n--;
		while(j > n1 && j < n && i > m1 && i < m){
			printf("%d ", x[i][j]);
			j--;
		}
		j++;
		i++;
		m1++;
	}
}
int main(int argc, char const *argv[])
{
	int m, n, i, j;
	int matrices[MAXLEN][MAXLEN];
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &matrices[i][j]);
		}
	}
	roundread(matrices, m, n); 
	return 0;
}
