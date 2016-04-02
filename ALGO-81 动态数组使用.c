#include <stdio.h>
#define MAXN	100
void fuction(int n, int *sum, int *pingjun)
{
	int i, a[MAXN];
	*sum = *pingjun = 0;	
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		*sum += a[i];
	}
	*pingjun = *sum / n;
}
int main()
{	
	int sum, pingjun, n;
	scanf("%d", &n);
	fuction(n, &sum, &pingjun);
	printf("%d %d", sum, pingjun);
	return 0;
}
