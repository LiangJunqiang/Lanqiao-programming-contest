#include <stdio.h>
int count = 0;
void layN(int n)
{
	if(n >= 1)
		layN(n - 1);
	else{
		count++;
		return;
	}
	if(n >= 2)
		layN(n - 2);
}
int main()
{
	int N;
	scanf("%d", &N);
	layN(N);
	printf("%d\n", count);
	return 0;
}
