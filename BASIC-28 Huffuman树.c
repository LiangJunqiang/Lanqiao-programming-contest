#include <stdio.h>
#define MAXn	100
//中文注释 
int chooseLeaf(int p[], int n)
{	//返回本次选择的花费cost
	int min1, min2, i, cost;
	min1 = n - 1;
	min2 = 0;
	for(i = 1; i < n; i++){
		if(p[min2] > p[i] && i != min1)
			min2 = i;
		if(p[min1] > p[n - i - 1] && (n - i - 1) != min2)
			min1 = n - i - 1;
	}
	cost = p[min1] + p[min2];
	p[(min1>min2)?min2:min1] = cost;
	for(i = (min1<min2)?min2:min1; i < n - 1; i++)
		p[i] = p[i + 1];
	return cost;
}
int main(int argc, char const *argv[])
{
	int n, i, p[MAXn] = {0}, totalcost = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &p[i]);
	while(n > 1)
		totalcost += chooseLeaf(p, n--);
	printf("%d\n", totalcost);
	return 0;
}