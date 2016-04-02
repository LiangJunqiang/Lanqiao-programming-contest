#include <stdio.h>
#include <memory.h>
#define MAXN	1000000
int flag[MAXN/32+1];
int primes[MAXN/3+1], pi;
long long result;
void fuction(int n)
{
	int i, j;
	pi = 0;
	result = 1;
	memset(flag, 0, sizeof(flag));
	for(i = 2; i < MAXN; i++)
		if(!((flag[i/32] >> (i % 32)) & 1)){
			primes[pi++] = i;
			result = (result * i) % 50000;
			if(pi >= n)
				break;
			for(j = i; j < MAXN; j += i)
				flag[j / 32] |= (1 << (j % 32));
		}
}
int main(int argc, char const *argv[])
{
	int i, n;
	scanf("%d", &n);
	fuction(n);
	printf("%d\n", result);
	return 0;
}
