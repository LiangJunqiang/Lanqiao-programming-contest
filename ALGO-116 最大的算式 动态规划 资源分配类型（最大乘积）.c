

#include <stdio.h>
#define MAXN	15
#define USED	-1
__int64 num[MAXN];
__int64 fuction(int n, int add)
{
	__int64 biggest = 1;
	int i, min = 0, min2 = 0, minadd[2];
	while(add--){
		for(i = 1; i < n; i++)	//选出最小的两数 min < min2 
			if(num[i] < num[min])
			{
				min2 = min;
				min = i;
			}
		//选最小的相邻和 
		if(min == 0)
			minadd[0] = 1;
		else if(min == n - 1)
			minadd[0] = n - 2;
		else{
			if(num[min + 1] > num[min - 1])
				minadd[0] = min - 1;
			else
				minadd[0] = min + 1;
		}
		if(min2 == 0)
			minadd[1] = 1;
		else if(min2 == n - 1)
			minadd[1] = n - 2;
		else{
			if(num[min2 + 1] > num[min2 - 1])
				minadd[1] = min2 - 1;
			else
				minadd[1] = min2 + 1;
		}
		//合并两最小相邻数，并标记其中一个为已使用 
		if(num[min] + num[minadd[0]] < num[min2] + num[minadd[1]]){
			printf("%d + %d = ", num[min], num[minadd[0]]);
			num[min] += num[minadd[0]];
			num[minadd[0]] = USED;
			printf("%d\n", num[min]);
		}
		else{
			printf("%d + %d = ", num[min2], num[minadd[1]]);
			num[min2] += num[minadd[1]];
			num[minadd[1]] = USED;
			printf("%d\n", num[min2]);
		}
	}
	for(i = 0; i < n; i++)
		if(num[i] != USED){
			biggest *= num[i];
			printf("* %lld\n", num[i]);
		}
	return biggest;
}
int main()
{
	int i;
	int N, K;
	scanf("%d%d", &N, &K);
	for(i = 0; i < N; i++)
		scanf("%lld", &num[i]);
	printf("%lld\n", fuction(N, N - K - 1));
	return 0;
}
