#include <stdio.h>
#include <memory.h>
#define MAX 21
char mark[MAX];
int count = 0;
int k;
void fillNum(int num[], int n)
{
	int i, j, cased = 0;
	while(num[n] <= k){
		memset(mark, 0, sizeof(mark));
		for(i = 1; i < n; i++)
			mark[num[i]] = 1;
		if(num[n - 1] > num[n - 2]){
			if(cased == 0){
				j = 1;
				cased = 1;
			}
			for(; j < num[n - 2] && mark[j] == 1; j++)
				;
			if(j >= num[n - 2]){	//相应范围已经没有可用的数 
				count++;
				return;
			}else{
				num[n] = j;			//找到最小的一个可用的数
				fillNum(num, n + 1);
			}
		}
		else{
			if(cased == 0){
				j = num[i - 2] + 1;
				cased = 1;
			}
			for(; j <= k && mark[j] == 1; j++)
				;
			if(j > k){		//相应范围已经没有可用的数 
				count++;				
				return;
			}else{
				num[n] = j;	//找到最小的一个可用的数 
				fillNum(num, n + 1);
			}
		}
		j++;
	}
}
int main()
{
	int num[MAX];
	scanf("%d", &k);
	memset(num, 0, sizeof(num));
	for(num[1] = 1; num[1] <= k; num[1]++)
	{
		num[2] = 0;
		while(num[2] <= k)
		{
			for(num[2]++; num[2] <= k && num[2] == num[1]; num[2]++)
				;
			if(num[2] > k)
				break;	
			fillNum(num, 3);
		}
	}
	printf("%d\n", count);
	return 0;
}
