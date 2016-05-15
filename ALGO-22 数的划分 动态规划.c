#include <stdio.h>
typedef long long LL;
LL M(int n, int r)
{
	if(r == 1 || n == r || n == r + 1)
		return 1;
	else if(n < r)
		return 0;
	else if(r == 2)
		return n/2;
	else return (M(n - r, r) + M(n - 1, r - 1));
} 
int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
	printf("%lld\n", M(n, m));
	return 0;
}
