#include <stdio.h>
#define MAXN	100
int main()
{
	long num[MAXN+1];
	int n, i, max = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if(num[max] < num[i])
			max = i;
	}
	printf("%d %d\n", num[max], max);
	return 0;
}
