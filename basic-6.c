#include <stdio.h>
main()
{
	int pascal[34][34], i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		pascal[i][i] = pascal[i][0] = 1;
	for(i = 2; i < n; i++)
		for(j = 1; j < i; j++)
			pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
	for(i = 0; i < n; i++){
		for(j = 0; j <= i; j++)
			printf("%d ", pascal[i][j]);
		putchar('\n');
	}
	
	return 0;
}
