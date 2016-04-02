#include <stdio.h>

int main()
{
	int n, m, i, j, k, l;
	int a[30][30], b[30][30], t[30][30] = {0};
	scanf("%d%d", &n, &m);
	getchar();
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	if(m == 0)
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; j++)
				if(i == j)
					a[i][j] = 1;
				else
					a[i][j] = 0;
	else if(m == 1)
		;
	else{
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; j++)
				b[i][j] = a[i][j];
		for(k = 2; k <= m; k++){
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					for(l = 0; l < n; l++)
						t[i][j] += a[i][l] * b[l][j];
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++){
					b[i][j] = t[i][j];
					t[i][j] = 0;
				}					
		}
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				a[i][j] = b[i][j];
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	return 0;
}
