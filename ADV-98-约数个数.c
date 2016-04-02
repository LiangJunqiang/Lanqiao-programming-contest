#include <stdio.h>
int main()
{
	int n, i, num = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		if((n/i)*i == n)
			num++;
	printf("%d", num);
	return 0;
}
