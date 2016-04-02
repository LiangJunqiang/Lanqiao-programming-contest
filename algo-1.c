#include <stdio.h>
main()
{
	int n, num[100], m, i, j, k, l, e, lrk[100][3], temp[100][100];
	scanf("%d", &n);
	// 输入数列 
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &m); 
	for(i = 0; i < m; i++)
		for(j = 0; j < 3; j++)
			scanf("%d", &lrk[i][j]);
	for(i = 0; i < m; i++){
		// 转移数段 
		for(j = lrk[i][0]; j <= lrk[i][1]; j++)
			temp[i][j - lrk[i][0]] = num[j - 1];
		l = 0;
		for(j = 0; j < (lrk[i][1] - lrk[i][0]); j++){
			l = j;
			for(k = l + 1; k <= (lrk[i][1] - lrk[i][0]); k++)
				if(temp[i][l] < temp[i][k])
					l = k;
			e = temp[i][l];
			temp[i][l] = temp[i][j];
			temp[i][j] = e;
		}
		printf("%d\n", temp[i][k - 1]);
	}
	return 0;
}
