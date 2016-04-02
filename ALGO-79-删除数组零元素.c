#include <stdio.h>
#define MaxCount 1000
int Compactlntegers(int num[], int n);
int main()
{
	int n, num[MaxCount], i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	n = Compactlntegers(num, n);
	printf("%d\n", n);
	for(i = 0; i < n; i++)
		printf("%d ", num[i]);
	return 0;
}//main
int Compactlntegers(int num[], int n)
{
	int zerosite[MaxCount], i, count, j = 0;
	for(i = 0; i < n; i++)
		if(num[i] == 0)
			zerosite[j++] = i;
	count = j;
	for(i = 0; i < count; i++)
		for(j = zerosite[i] + 1; j < n && (j < zerosite[i + 1] || i == count - 1); j++)
			num[j - i - 1] = num[j];			
	return (n - count);
}//Compactlntegers
