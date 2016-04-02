#include "stdio.h"
#define MAXSIZE 10000
int main(int argc, char const *argv[])
{
	int n, i, j, carry_over = 0;
	int numbit[MAXSIZE] = {0};
	numbit[0] = 1;
	scanf("%d", &n);
	for (i = 2; i <= n; ++i)
	{
		for (j = 0; j < MAXSIZE; ++j)
		{
			numbit[j] = numbit[j] * i + carry_over;
			if((carry_over = numbit[j]/10))
				numbit[j] %= 10;
		}
	}
	for (i = MAXSIZE - 1; numbit[i] == 0; i--)
		;
	while(i >= 0)
		printf("%d", numbit[i--]);
	return 0;
}
