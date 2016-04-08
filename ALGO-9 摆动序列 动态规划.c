#include <stdio.h>
#include <memory.h>
#define MAX 21
char mark[MAX];
int main()
{
	int k;
	int num[MAX];
	int i, j, m, n, l;
	long count = 0;
	scanf("%d", &k);
	for(num[1] = 1; num[1] <= k; num[1]++)
	{
		num[2] = 0;
		while(num[2] <= k)
		{
			for(num[2]++; num[2] <= k && num[2] == num[1]; num[2]++)
				;
			if(num[2] > k)
				break;
			for(i = 3; i <= k; i++)
			{
				memset(mark, 0, sizeof(mark));
				for(l = 1; l < i; l++)
					mark[num[l]] = 1;
				if(num[i - 1] > num[i - 2]){
					for(j = 1; j < num[i - 2] && mark[j] == 1; j++)
						;
					if(j >= num[i - 2]){	//相应范围已经没有可用的数 
						count++;
						for(n = 1; n < i; n++)
							printf("%d ", num[n]);
						putchar('\n');
						break;
					}else{
						num[i] = j;			//找到最小的一个可用的数 
					}
				}
				else{
					for(j = num[i - 2] + 1; j <= k && mark[j] == 1; j++)
						;
					if(j > k){		//相应范围已经没有可用的数 
						count++;
						for(n = 1; n < i; n++)
							printf("%d ", num[n]);
						putchar('\n');
						break;
					}else{
						num[i] = j;	//找到最小的一个可用的数 
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
