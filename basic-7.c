#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	for (i = 105; i < 998; ++i)
		if (pow(i / 100, 3) + pow((i / 10) % 10, 3) + pow(i % 10, 3) == i)
			printf("%d\n", i);
	return 0;
}
