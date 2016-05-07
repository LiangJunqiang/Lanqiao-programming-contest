#include <stdio.h>
#include <string.h>
int W;
int flag;
void fun(int n[], int y[], int t[], int chose[], int sumtime);
int main()
{
	int n[101], y[101], t[101], chose[201];
	int i;
	memset(y, 0, sizeof(y));
	memset(t, 0, sizeof(t));
	scanf("%d%d", &n[0], &W);
	for(i = 1; i <= n[0]; i++)
	{
		scanf("%d", &n[i]);
		t[0] += (n[i]*2);
	}
	flag = 0;
	fun(n, y, t, chose, 0);
	if(flag == 0)
		printf("No\n");
	return 0;
}
void fun(int n[], int y[], int t[], int chose[], int sumtime)
{	//n[0]为需要算加法的数字个数，n[1...n[0]]为这n[0]个数；
	//y[0]y, y[1...n[0]]为yi, t[i]为第i个算法执行的语句次数
	int i, temp, j;
	if(sumtime >= t[0])
	{
		if(y[0] == W)
		{
			printf("Yes\n");
			for(j = 1; j <= sumtime; j++)
				printf("%d ", chose[j]);
			putchar('\n');
			flag = 1;
		}
		return;
	}
	if(flag == 1 || sumtime > t[0])
		return;
	for(i = 1; i <= n[0]; i++)
	{
		if(t[i] < n[i] * 2)
		{
			t[i]++;
			sumtime++;
			chose[sumtime] = i;
			if(t[i] % 2 == 1)	//执行第一条
			{
				temp = y[i];
				y[i] = y[0];
				fun(n, y, t, chose, sumtime);
				y[i] = temp;
			}
			else				//执行第二条 
			{
				temp = y[0];
				y[0] = y[i] + 1;
				fun(n, y, t, chose, sumtime);
				y[0] = temp;
			}
			t[i]--;
			sumtime--;
		}
	}
}
