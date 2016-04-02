#include <stdio.h>

int main()
{
	int i, j;
	for(i = 1; i <= 9; i++)
		for(j = 0; j <= 9; j++)
			printf("%d\n", i*1001+j*110);
	return 0;
}
