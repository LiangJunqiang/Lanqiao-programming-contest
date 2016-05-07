#include <stdio.h>
#include <string.h>
char GL[100][1000];
int main()
{
	int n, m;
	int i, j;
	int p, q;
	memset(GL, 0, sizeof(GL));
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &p, &q);
		GL[p - 1][i] = 1;
		GL[q - 1][i] = -1;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			printf("%d ", GL[i][j]);
		putchar('\n');
	}
	return 0;
} 
