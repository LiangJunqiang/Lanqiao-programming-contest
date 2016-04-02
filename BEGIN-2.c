#include<stdio.h>
int main()
{
	long long a;
	scanf("%I64d",&a);
	printf("%I64d",(a*(a+1))/2);
	return 0;
}