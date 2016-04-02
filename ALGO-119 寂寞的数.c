#include <stdio.h>
#include <string.h>
#define MAXN	10001
void printJIMOnum(int n)
{
	static int num[MAXN];
	int i, creat;
	num[0] = -1;
	memset(num, -1, (n+2)*sizeof(int));
	for(i = 0; i < n; i++)
	{
		if(i >= 10000)
			creat = i + (i%10) + (i/10%10) + (i/100%10) + (i/1000%10) + (i/10000%10);
		else if(i >= 1000)
			creat = i + (i%10) + (i/10%10) + (i/100%10) + (i/1000%10);
		else if(i >= 100)
			creat = i + (i%10) + (i/10%10) + (i/100%10);
		else if(i >= 10)
			creat = i + (i%10) + (i/10%10);
		else
			creat = i + (i%10);
		num[creat] = i;
		if(num[i] == -1)
			printf("%d\n", i);
	}
}
int main ()
{
	int n; 
	scanf("%d", &n);
	printJIMOnum(n);
	return 0;
}
