#include <stdio.h>
#define ArrNum	8
#define MAX	1000000
#define MIN -1000000
int MinMultiply(int a[], int b[], int len)
{
	int i, j, minmultiply = 0, max, min;
	for(i = 0; i < len; i++)
	{
		max = min = 0;
		for(j = 1; j < len; j++){
			if(a[j] > a[max])
				max = j;
			if(b[j] < b[min])
				min = j;
		}
		minmultiply += a[max] * b[min];
		a[max] = MIN;
		b[min] = MAX;
	}
	return minmultiply;
}//MinMultiply
int main(int argc, char const *argv[])
{
	int count, i;
	int a[ArrNum], b[ArrNum], len;
	scanf("%d", &count);
	while(count--){
		scanf("%d", &len);
		for(i = 0; i < len; i++)
			scanf("%d", &a[i]);
		for(i = 0; i < len; i++)
			scanf("%d", &b[i]);
		printf("%d\n", MinMultiply(a, b, len));
	}
	return 0;
}
